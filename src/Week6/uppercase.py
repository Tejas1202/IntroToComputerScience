# Don't have to worry about looping and making each character uppercase unlike in C
# string types already have functions for that
s = input("Before: ")
print("After: ", end="")
print(s.upper())