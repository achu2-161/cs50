import csv
import sys
from sys import argv

def main():

    # TODO: Check for command-line usage

    if len(argv) != 3:
        print("Incorrect number of command line arguments")

    # TODO: Read database file into a variable

    with open(argv[1]) as database:
        database_reader = csv.DictReader(database)
        for database_row in database_reader:

            print(database_row)

    # TODO: Read DNA sequence file into a variable

    with open(argv[2]) as dna:
        dna_sequence = dna.read()

        print(dna_sequence)

    # TODO: Find longest match of each STR in DNA sequence

    STRs = list(database_row.keys())        # list STRs in database

    number_STR = len(STRs) - 1              # determine how many STRs are in the list

    print(f"Number of STRs is", number_STR)

    for x in range(number_STR):             #loops through each STR

        print(f"STR", x + 1, "is", STRs[x + 1])

        lr = longest_match(dna_sequence, STRs[x + 1])

        print(lr)

    for x in database_row:      # checks each row of the database i.e. each person

        for z in range(4):      # loops to go through the different STRs in for each person

            STR_tracker = []

            #y =    # y is the list of all the keys i.e. STRs

            #print(y)

            # personal_STR = STR_tracker.append(y)

            # largest_personal_STR = max(personal_STR)

            # print(personal_STR)

        #lr = longest_match(dna_sequence, y[z])

        #print(lr)

    # TODO: Check database for matching profiles



    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run




main()
