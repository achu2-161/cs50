x = input ("enter text: ")
for c in x:
    if c.islower():
        print(c, end = "")
    else:
        print("_", end = "")
        print(c.lower(), end = "")
print()