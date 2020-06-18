from cs50 import get_int

def main():
    i = get_positive_int()
    print(i)

# so even if n is defined in a local scope, we can still return it
# as variables are accessible anywhere inside a local function (but not across functions)
def get_positive_int():
    while True:
        n = get_int("Positive integer: ")
        if n > 0:
            break
    return n

main()