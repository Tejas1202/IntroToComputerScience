import re # Regular expressions library

s = input("Do you agree?\n")

# ^ means it should really start with a y, (es)? means followed by es is optional, $ means it should end there
if re.search("^y(es)?$", s, re.IGNORECASE):
    print("Agreed.")
elif re.search("no|n", s):
    print("Not agreed.")