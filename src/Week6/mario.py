# program to print ? horizontally and # vertically and 2D block
# as print have by default \n, so we passed a name argument end and assigned it's value to nothing (which by default is \n)
for i in range(4):
    print("?", end="")
print()

print("Pythonic way")
print("?" * 4)

for i in range(3):
    print("#")

print("Pythonic way")
print("#\n" * 3, end="")

print("Printing 2D block")
for i in range(3):
    for j in range(3):
        print("#", end="")
    print()