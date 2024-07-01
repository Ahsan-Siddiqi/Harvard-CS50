height = input("Height: ")

num = height

for i in height:
    for j in height * 2 + 1:
        if j < height - i:
            print(" " end='')
        elif j == height - i:
            print("#" end='')
        

    print("#" end='')
    print()
