height = int(input("Height: "))

while(height > 8 or height < 1):
    height = int(input("Height: "))

for i in range(height):
    for j in range(height):
        j += 1
        if j <= height - i - 1:
            print(" ", end='')
        else:
            print("#", end='')

    print("  ", end='')

    for k in range(i + 1):
        print("#", end='')

    print()
