# can't call cough directly but as python doesn't have prototypes like C have, we defined a main (which can be called anything)
# and calling it at the bottom
def main():
    cough(3)

def cough(n):
    for i in range(n):
        print("cough")

main()