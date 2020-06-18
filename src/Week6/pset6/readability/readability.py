while True:
    text = input("Text: ")
    if text.strip():
        break

endOfSentence = ['.', '?', '!']
letters = 0
average_number_of_words = 100

# As the last word won't have space after it, hence initializing from 1
words = 1
sentences = 0
for c in text:
    if c.isalpha():
        letters += 1
    elif c == ' ':
        words += 1
    elif c in endOfSentence:
        sentences += 1

# Average number of letters per average_number_of_words
L = (average_number_of_words * letters) / words

# Average number of sentences per average_number_of_words
S = (average_number_of_words * sentences) / words

# Coleman-Liau index
index = round(0.0588 * L - 0.296 * S - 15.8)

if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")
