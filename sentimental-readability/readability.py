text = input("Text: ")

# compute L and S
punc = ["!", ".", "?"]
sentences = 0
chars = 0

for char in text:
    if char in punc:
        sentences += 1
    if char.isalpha():
        chars += 1

words = len(text.split())

L = (chars / words) * 100
S = (sentences / words) * 100

# compute index
index = 0.0588 * L - 0.296 * S - 15.8

# print
if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}" )
