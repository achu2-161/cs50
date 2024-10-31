height = int(input("Height: "))

#while(height >= 1 and height <=8):

for row in range(height):
    for column in range(height - row - 1):
        print(f" ", end='')
    for column in range(row+1):
        print(f"#", end='')
    print(f"")

