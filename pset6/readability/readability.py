# Collecting user-input
text = input("Text: ")

# Collecting values needed to calculate Coleman-Liau index
letters = 0
words = 1
sentences = 0

# Getting length of user input to use for loops
length = len(text)

# Loop checking for alphabet values
for i in range(length):
    if (text[i].isalpha() == True):
        letters = letters + 1

# Loop checking for number of words in user input
for j in range(length):
    if j != 0 and text[j] == ' ':
        words = words + 1;

# Loop for checking number of sentences
for k in range(length):
    if text[k] == '!' or text[k] == '.'or text[k] == '?':
        sentences = sentences + 1

# Index calculations
L = (float(letters)/float(words)) * 100
S = (float(sentences)/float(words)) * 100
index = round((0.0588 * L) - (0.296 * S) - 15.8);

# Conditions to output reading grade level of user input
if index >= 16:
    print("Grade 16+")

elif index <= 0:
    print("Before Grade 1")

else:
    print("Grade " + str(index))