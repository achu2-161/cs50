s = input("Text: ")

# number of letters

characters = len(s)

# number of letters

letters = 0
words = 1
sentences = 0

for a in range(characters):


    if (s[a].islower() == True or s[a].isupper() == True):

        letters += 1

# number of words

for b in range(characters):

    if(s[b].isspace() == True):

        words += 1

# number of sentences

for c in range (characters):

    if(s[c] == "." or s[c] == "!" or s[c] == "?"):

        sentences += 1

# print(sentences)

# print(sentences)
# print(words)
# print(letters)

L = (letters / words) * 100
S = (sentences / words) * 100

index = round((0.0588 * L) - (0.296 * S) - 15.8)

# print(L)
# print(S)

# print (index)

if (index < 1):

    print("Before Grade 1")

elif (index > 16):

    print ("Grade 16+")

else:

    print(f"Grade", index)
