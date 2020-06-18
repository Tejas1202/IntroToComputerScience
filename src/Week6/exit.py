# exit function in Python equivalent to return in C

from sys import argv, exit

if len(argv) != 2:
    print("Missing command-line arguments")
    exit(1)
print(f"hello, {argv[1]}")