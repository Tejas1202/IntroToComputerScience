#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int calculate_coleman_liau_index(int numberOfWords, int numberOfLetters, int numberOfSentences);
void specify_grade(int index);

const int averageNumberOfWords = 100; //As index is calculated on average number of 100 words

int main(void)
{
    string text = get_string("Text: ");
    int index = calculate_coleman_liau_index(count_words(text), count_letters(text), count_sentences(text));
    specify_grade(index);
}

int count_letters(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            count++;
        }
    }
    return count;
}

int count_words(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            count++;
        }
    }
    return ++count; //as the last word won't have any space after it
}

int count_sentences(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            count++;
        }
    }
    return count;
}

//Calculates index based on letters and sentences based on fixed averageNumberOfWords
int calculate_coleman_liau_index(int numberOfWords, int numberOfLetters, int numberOfSentences)
{
    float lettersPerAverageWords = numberOfLetters * averageNumberOfWords / (float) numberOfWords;
    float sentencesPerAverageWords = numberOfSentences * averageNumberOfWords / (float) numberOfWords;

    int index = round(0.0588 * lettersPerAverageWords - 0.296 * sentencesPerAverageWords - 15.8);

    return index;
}

void specify_grade(int index)
{
    if (index < 1)
    {
        printf("Before Grade 1");
    }
    else if (index >= 16)
    {
        printf("Grade 16+");
    }
    else
    {
        printf("Grade %i", index);
    }
    printf("\n");
}