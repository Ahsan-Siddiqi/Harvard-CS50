import re

while(True):
    try:
        card = int(input("Number: "))
        if card is not isinstance(card, int):
            break
    except ValueError:
        continue

card = str(card)

patterns = {
    'VISA': r'^4\d{12}(\d{3})?$',
    'MASTERCARD': r'^5[1-5]\d{14}$|^2(22[1-9]|2[3-9]\d|[3-6]\d{2}|7([01]\d|20))\d{12}$',
    'AMEX': r'^3[47]\d{13}$',
}

reverse = card[::-1]
total = 0

for i, num in enumerate(reverse):
    n = int(num)
    if i % 2 == 1:
        n *= 2
        if n > 9:
            n-= 9
    total += n

if total % 10 != 0:
    print("INVALID")
    exit()

for type, pattern in patterns.items():
    if re.match(pattern, card):
        print(type)
        exit()

print("INVALID")
