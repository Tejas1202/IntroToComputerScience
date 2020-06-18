# Arrays in python are lists that can grow and shrink in size
scores = []
scores.append(72)
scores.append(73)
scores.append(33)
# Or you can declare just like scores = [72, 73, 33]

print(f"Average: {sum(scores) / len(scores)}")
