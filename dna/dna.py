import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py filename.csv filename.txt")
        exit()

    # TODO: Read database file into a variable
    csvRows = []

    with open(sys.argv[1]) as data:
        reader = csv.DictReader(data)
        for row in reader:
            csvRows.append(row)

    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2]) as input:
        inputSequence = input.read().strip()

    # TODO: Find longest match of each STR in DNA sequence
    strs = ["AGATC", "TTTTTTCT", "AATG", "TCTAG", "GATA", "TATC", "GAAA", "TCTG"]
    longest = {}
    for str in strs:
        longest[str] = longest_match(inputSequence, str)

    # TODO: Check database for matching profiles
    for row in csvRows:
        match = True
        for str, n in row.items():
            if str != 'name':
                # print(f"STR: {str}, n: {n}, Longest: {longest[str]}, name: {row['name']}")
                if int(n) != int(longest[str]):
                    match = False

        if match:
            print(row['name'])
            return

    print("No Match")

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
