x, y, z = input("Enter Expression: ").split(" ")

a = float(x)
b = float(z)

if (y == "+"):
    print(a+b)
elif(y == "-"):
    print(a-b)
elif(y == "*"):
    print(a*b)
elif(y == "/"):
    print(a/b)