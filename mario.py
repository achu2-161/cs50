height = 0

try:
    while(height < 1 or height >8):
        height = int(input("Height: "))
except ValueError:
    print("not an integer")

for row in range(height):
    for column in range(height - row - 1):
        print(f" ", end='')
    for column in range(row+1):
        print(f"#", end='')
    print(f"")

