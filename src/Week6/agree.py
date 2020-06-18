from cs50 import get_string

s = get_string("Do you agree?\n")

#Hence no need to verbosely type all the OR conditions for handling multiple cases
if s.lower() in ["y","yes"]:
    print("Agreed")
elif s.lower() in ["n", "no"]:
    print("Not agreed")