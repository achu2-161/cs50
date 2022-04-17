x = input("What is the Answer to the Great Question of life, the Universe and Everything? " ).replace("-", " ").casefold()

if x == "42" or x == "forty two":
    print("Yes")
else:
    print("No")