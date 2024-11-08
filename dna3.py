import csv
import sys
from sys import argv

def main():

    # TODO: Check for command-line usage

    if len(argv) != 3:
        print("Incorrect number of command line arguments")

    # TODO: Read database file into a variable

    db_dict = []

    k = 0       # k is the number of names

    with open(argv[1]) as database:
        database_reader = csv.DictReader(database)
        for database_row in database_reader:
            db_dict.append(database_row)
            #print(database_row)
            k += 1

    #print(k)

    # TODO: Read DNA sequence file into a variable

    with open(argv[2]) as dna:
        dna_sequence = dna.read()

        #print(dna_sequence)

    # TODO: Find longest match of each STR in DNA sequence

    DNA_dict = {}                           #create dict to store STR/longest run pair

    STRs = list(database_row.keys())        # list STRs in database

    number_STR = len(STRs) - 1              # determine how many STRs are in the list

    #print(f"Number of STRs is", number_STR)

    for x in range(number_STR):             # loops through each STR

        #print(f"STR", x + 1, "is", STRs[x + 1])

        lr = longest_match(dna_sequence, STRs[x + 1])       # call function Longest_match to determine longest run stored in variable lr

        new_pair = {STRs[x + 1]: lr,}       # create dictionary to store STR and highest sequence

        DNA_dict.update(new_pair)           # update DNA_dict

        #print(lr)

    dna_keys = list(DNA_dict.keys())
    dna_values = list(DNA_dict.values())

    n = 1

    db_value = list(db_dict[n].values())
    db_name = db_value[0]
    db_clean = db_value.remove(db_name)

    print (db_clean)   #list from the database. use [n] to access individual dictionaries in the list
    print (db_value)
    print (list(DNA_dict.values()))

    #print(f"dna",DNA_dict)


    # TODO: Check database for matching profiles

    db_length = len(database_row) - 1


    for name in range(k):

        for b in range(db_length):      #remove this loop, add if statemen with and statement to check all 3 STRs

            db = (db_dict[name])

            db_keys = list(db)
            db_values = db[db_keys[b + 1]]

            if(dna_values[b] == db_values):
                print(db[db_keys[0]])

            #else:
                #print("no match")

            #print(f"db keys",db_keys[b + 1])
            #print(f"db values", db_values)
            #print(f"dna value", dna_values[b])
            #print(f"name", db[db_keys[0]])




        #print(db)




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
