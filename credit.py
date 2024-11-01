number = int(input("Number: "))

# Extract each digit from the number, up to a maximum of 16 digits
digits = [int(d) for d in str(number).zfill(16)[-16:]]

# Calculate sums for Luhn algorithm
odd_sum = sum(digits[-1::-2])  # Sum of digits at odd positions (from right)
even_sum = sum(sum(divmod(2 * d, 10)) for d in digits[-2::-2])  # Sum of double of even-position digits (split if >9)
total_sum = odd_sum + even_sum

length = len(str(number))

# Determine starting digits
start_13 = number // 10**(length - 13) if length >= 13 else None
start_15 = number // 10**(length - 15) if length >= 15 else None
start_16 = number // 10**(length - 16) if length >= 16 else None

# Check card type and validity
if total_sum % 10 == 0:
    if length == 15 and start_15 in {34, 37}:
        print("AMEX")
    elif (length == 13 and start_13 == 4) or (length == 16 and start_16 == 4):
        print("VISA")
    elif length == 16 and start_16 in {51, 52, 53, 54, 55}:
        print("Mastercard")
    else:
        print("Invalid")
else:
    print("Invalid")
