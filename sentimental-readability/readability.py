text = input("Text: ")

# compute L and S
punc = ["!", ".", "?"]
sentances, chars = 0

for char in text:
    if char in punc:
        sentances += 1
    chars += 1

L = chars / 100
S = sentances / 100

# compute index
index = 0.0588 * L - 0.296 * S - 15.8

# print
if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print("Grade " + index)
