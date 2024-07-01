height = input("Height: ")

num = height

for i in height:
    for j in height:
        if j < height - i:
            print(" " end='')
        else:
            print("#" end='')

    print(" " end='')

    for k in range(i):
        print("#" end='')

    print()
