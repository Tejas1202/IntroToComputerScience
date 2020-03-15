#include <stdio.h>
#include <cs50.h>

float average(int length, int array[]);

int main(void)
{
    int numberOfScores = get_int("Scores: ");
    int scores[numberOfScores];

    for (int i = 0; i < numberOfScores; i++)
    {
        scores[i] = get_int("Score %i: ", i + 1);
    }

    printf("Average: %.1f\n", average(numberOfScores, scores));
}

float average(int length, int array[])
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return (float) sum / length;
}