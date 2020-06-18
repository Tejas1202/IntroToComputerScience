# curly braces indicating python that it's a dictionary

from sys import exit

people = {
    "EMMA": "617-555-0100",
    "RODRIGO": "617-555-0101",
    "DAVID": "617-555-0102",
    "BRIAN": "617-555-0103"
}

if "DAVID" in people:
    print(f"Found {people['DAVID']}")
    exit(0)
print("Not found")
exit(1)