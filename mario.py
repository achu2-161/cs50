height = int(input("Height: "))

for row in range(height):
    for column in range(height - row):
        print(f" ", end='')
    for column in range(row+1):
        print(f"#", end='')
    print(f"")

