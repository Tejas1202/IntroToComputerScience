# https://www.geeksforgeeks.org/python-all-occurrences-of-substring-in-string/

from sys import argv, exit
from csv import reader, DictReader

if len(argv) is not 3:
    print("Missing command line arguments")
    exit(0)

# Open person's dna sequences and read to a string
with open(argv[2], 'r') as dnaSampleFile:
    dna = dnaSampleFile.read()

# Open dna database and get first row for getting STR names
with open(argv[1]) as dnaDatabaseFile:
    fileReader = reader(dnaDatabaseFile)
    for row in fileReader:
        strsList = row
        strsList.pop(0)
        break

# Dictionary for with person's str as key and count as value
personStrCount = {}

for str in strsList:
    # Get all the occurence of a particulat str in dna (list of indexes)
    strOccurencesIndexList = [i for i in range(len(dna)) if dna.startswith(str, i)]

    # Finding maximum consecutive occurence using concept of Arithmetic Progression
    if len(strOccurencesIndexList) > 0:
        maxConsecutiveIndex = 1
        temp = 1
        start = strOccurencesIndexList[0]
        strLength = len(str)
        for item in strOccurencesIndexList[1:]:
            if strLength + start == item:
                temp = temp + 1
            elif temp > maxConsecutiveIndex:
                maxConsecutiveIndex = temp
                temp = 1
            start = item

        personStrCount[str] = temp if temp > maxConsecutiveIndex else maxConsecutiveIndex
    else:
        personStrCount[str] = 0

with open(argv[1]) as dnaDatabaseFile:
    people = DictReader(dnaDatabaseFile)

    for person in people:
        matchCount = 0
        for key in personStrCount:
            if personStrCount[key] == int(person[key]):
                matchCount += 1

        if matchCount == len(personStrCount):
            print(person['name'])
            exit(0)

print("No match")