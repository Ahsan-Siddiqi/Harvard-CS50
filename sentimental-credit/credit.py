import re

while(True):
    try:
        card = int(input("Number "))
        if card is isinstance(card, int):
            break
    except ValueError:
        continue

str(card)

patterns = {
    'Visa': r'^4\d{12}(\d{3})?$',
    'MasterCard': r'^5[1-5]\d{14}$|^2(22[1-9]|2[3-9]\d|[3-6]\d{2}|7([01]\d|20))\d{12}$',
    'American Express': r'^3[47]\d{13}$',
    'Discover': r'^6(011|5\d{2}|4[4-9]\d)\d{12}$'
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

if total % 10 is not 0:
    print("INVALID")

