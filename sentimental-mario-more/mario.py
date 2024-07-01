height = input("Height: ")

length = len(height)

for i in range(length):
    for j in range(length):
        if j < length - i:
            print(" ", end='')
        else:
            print("#", end='')

    print(" ", end='')

    for k in range(i):
        print("#", end='')

    print()
