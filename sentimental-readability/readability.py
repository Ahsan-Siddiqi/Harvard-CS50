text = input("Text: ")

# compute L and S
for char in text:

# compute index
index = 0.0588 * L - 0.296 * S - 15.8

# print
if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+)
else:
    print("Grade " + index)
