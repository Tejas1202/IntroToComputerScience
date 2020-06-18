# For taking command line arguments, there's no main function in python but
# we can import from system library
from sys import argv

# long way: for i in range(len(argv)) print(argv[i])
for arg in argv:
    print(arg)