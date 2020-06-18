# input function always returns a string
s = input("Input: ")
print("Output: ", end="")

# hence no need to take care of looping till length condition amd do s[index] unlike in C
for c in s:
    print(c, end="")
print()