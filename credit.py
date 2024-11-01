number = int(input("Number: "))

# Extract each digit using modulus and integer division
x_1 = (number % 10)
x_2 = (number % 100) // 10
x_3 = (number % 1000) // 100
x_4 = (number % 10000) // 1000
x_5 = (number % 100000) // 10000
x_6 = (number % 1000000) // 100000
x_7 = (number % 10000000) // 1000000
x_8 = (number % 100000000) // 10000000
x_9 = (number % 1000000000) // 100000000
x_10 = (number % 10000000000) // 1000000000
x_11 = (number % 100000000000) // 10000000000
x_12 = (number % 1000000000000) // 100000000000
x_13 = (number % 10000000000000) // 1000000000000
x_14 = (number % 100000000000000) // 10000000000000
x_15 = (number % 1000000000000000) // 100000000000000
x_16 = (number % 10000000000000000) // 1000000000000000

# Double alternate digits starting from x_2 to x_16
y_2 = x_2 * 2
y_4 = x_4 * 2
y_6 = x_6 * 2
y_8 = x_8 * 2
y_10 = x_10 * 2
y_12 = x_12 * 2
y_14 = x_14 * 2
y_16 = x_16 * 2

# Calculate Luhn sum
lund_1 = (x_1 + x_3 + x_5 + x_7 + x_9 + x_11 + x_13 + x_15)
lund_2 = ((y_2 // 10) + (y_2 % 10) + (y_4 // 10) + (y_4 % 10) +
          (y_6 // 10) + (y_6 % 10) + (y_8 // 10) + (y_8 % 10) +
          (y_10 // 10) + (y_10 % 10) + (y_12 // 10) + (y_12 % 10) +
          (y_14 // 10) + (y_14 % 10) + (y_16 // 10) + (y_16 % 10))
lund_3 = lund_1 + lund_2

# Check card length
length = len(str(number))

# Identify starting digits
start_13 = (number % 10000000000000) // 1000000000000
start_15 = (number % 1000000000000000) // 100000000000000
start_16V = (number % 10000000000000000) // 1000000000000000
start_16M = (number % 10000000000000000) // 100000000000000

# Check for American Express
if (lund_3 % 10 == 0) and ((start_15 == 34) or (start_15 == 37)) and length == 15:
    print("AMEX")

# Check for VISA
elif (lund_3 % 10 == 0) and ((start_13 == 4) or (start_16V == 4)) and (length == 13 or length == 16):
    print("VISA")

# Check for MasterCard
elif (lund_3 % 10 == 0) and (start_16M in {51, 52, 53, 54, 55}) and length == 16:
    print("Mastercard")

# Invalid card
else:
    print("Invalid")
