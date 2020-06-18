from cs50 import get_float

while True:
    change = get_float("Change owed: ")
    if change >= 0:
        break
cents = change * 100
coins = 0

while cents > 0:
    if (cents - 25) >= 0:
        cents -= 25
    elif (cents - 10) >= 0:
        cents -= 10
    elif (cents - 5) >= 0:
        cents -= 5
    else:
        cents -= 1
    coins += 1

print(coins)
