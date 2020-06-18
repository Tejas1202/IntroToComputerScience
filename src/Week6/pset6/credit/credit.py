from cs50 import get_string
from sys import exit
from math import floor

# AMERICAN EXPRESS
AE = ["34", "37"]

# MASTERCARD
MC = ["51", "52", "53", "54", "55"]

# VISA
VISA = "4"

brand = "INVALID"
card = get_string("Number: ")

# remove any trailing spaces
card = card.strip()
card_length = len(card)

if card_length not in [13, 15, 16]:
    print(brand)
    exit(0)

if card_length == 15:
    if card[:2] in AE:
        brand = "AMEX"
elif card_length == 13:
    if card[:1] == VISA:
        brand = "VISA"
else:
    if card[:2] in MC:
        brand = "MASTERCARD"
    elif card[:1] == VISA:
        brand = "VISA"

# Don't validate checksum if brand still remains INVALID
if brand == "INVALID":
    print(brand)
    exit(0)

# casting string to int
card = int(card)
second_last_digits_series_sum = 0
last_digits_series_sum = 0
while card > 0:
    last_digits_series_sum += card % 10
    # removing the already processed digit
    card /= 10
    # remove the decimal point and it's post digit
    card = floor(card)
    remainder = (card % 10) * 2

    if remainder > 9:
        second_last_digits_series_sum += remainder % 10
        remainder = floor(remainder / 10)
        second_last_digits_series_sum += remainder
    else:
        second_last_digits_series_sum += remainder

    card /= 10
    card = floor(card)

if (last_digits_series_sum + second_last_digits_series_sum) % 10 == 0:
    print(brand)
else:
    print("INVALID")