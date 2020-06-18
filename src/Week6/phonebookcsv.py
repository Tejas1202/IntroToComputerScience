# Saves names and numbers to a CSV file

import csv # csv package (libraries are called packages in Python)
from cs50 import get_string

# Get name and number
name = get_string("Name: ")
number = get_string("Number: ")

# Open CSV file (don't have to worry about closing file if you're using with syntax)
with open("phonebook.csv", "a") as file:

    # Print to file
    writer = csv.writer(file)
    writer.writerow((name, number))