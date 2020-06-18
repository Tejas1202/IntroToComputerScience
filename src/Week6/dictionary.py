# set is a dictionary containing unique values, hence it will take care not to store duplicates
# implementing dictionary of pset5 in Python

words = set()

def check(word):
    if word.lower() in words:
        return True
    else:
        return False

def load(dictionary):
    file = open(dictionary, "r")
    # As for loop in Python is much more powerful, so we can directly loop over it
    for line in file:
        words.add(line.rstrip("\n")) # Add word by removing \n at the end to our set words
    file.close()
    return True

def size():
    return len(words)

def unload():
    return True

