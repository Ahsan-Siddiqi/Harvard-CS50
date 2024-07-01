height = int(input("Height: "))

for i in range(height):
    for j in range(height):
        if j < height - i:
            print(" ", end='')
        else:
            print("#", end='')

    print("  ", end='')

    for k in range(i):
        print("#", end='')

    print()
