import csv
import sys
import numpy

# Making sure that the correct number of command-line arguments are present using the sys module
if len(sys.argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")

# Program continues if correct number of command-line arguments are present
else:
    # Opening csv file for the first time into a dictionary
    with open(sys.argv[1]) as csvfile:
        dictionary = csv.DictReader(csvfile)

        # Getting the keys from the dictionary. These include the STRs in the program
        keys = dictionary.fieldnames
        names = []
        strs = []

        # Gets STRs from the keys list, leaving behind the "Name" key, which references the names of those in the csv file
        for i in range(1, len(keys)):
                strs.append(keys[i])

        # Saving the names of those in the csv file in order of appearance, to be used for printing out the DNA match
        for row in dictionary:
            names.append(row['name'])

    # Opening the txt file containing the DNA sequence being compared to the csv file, and saving it in 'sequence'
    file = open(sys.argv[2], mode='r')
    sequence = file.read()

    temp = 0
    strcounts = [0] * len(strs)
    # This part of the program iterates through all of the STRs specified in the csv file, and counts the highest number of consecutive appearances for each one.
    # These numbers then get saved in strcounts, in the same order of the STRs.
    for i in range(len(strs)):
        # An important detail is that iteration through the DNA sequence occurs using each character in the sequence as a starting point.
        for x in range(0, len(strs[i])):
            # Scanning the sequence in chunks that are the size of the STR being checked at that given moment.
            for j in range(x, len(sequence),len(strs[i])):
                k = j + len(strs[i])
                # Keep adding to temp for each consecutive time the STR appears. If it stops appearing, save that as the highest appearance count, and reset temp to 0.
                if sequence[j:k] == strs[i]:
                    temp = temp + 1
                    if temp > strcounts[i]:
                        strcounts[i] = temp
                else:
                    temp = 0

    templist = []
    counter = 0
    divide = 0
    divide2 = 0

    # Reopening the csv file to collect all of the STR counts. But due to the nature of DictReader objects, the values will be stored in templist in an incorrect order.
    for i in range(0, len(strs)):
        dictionary = csv.DictReader(open(sys.argv[1]))
        for row in dictionary:
            templist.append(row[strs[i]])
        while counter == 0:
    # To correct this order, we need to place every nth value next to each other, where n is the number of columns of data. This value will be called divide2.
            divide2 = divide2 + len(templist)
            counter = counter + 1

    # Divide will hold the number of rows of data, which is the same as the number of STRs.
    divide = int(len(strs))

    # yesvariable will tell us when a match is found at the end of the program.
    yesvariable = 0
    finallist = [0]*len(templist)
    count = 0
    candidate = 0
    realcand = 0

    # Using the divide2 value, the templist gets sorted in order in a new list called finallist.
    for i in range(0, divide2):
        for j in range(i, len(templist), divide2):
            temp2 = int(templist[j])

            for z in range(count, len(templist)):
                finallist[z] = temp2
            count = count + 1

    # This part of the program compares each person's (candidate's) STR counts with the counts found when scanning the sequence.
    for y in range(0, len(finallist), divide):
        a = y + divide
        templist = finallist[y:a]

    # Because comparing lists wasn't working, I multiplied all of the STR counts together for both the csv and sequence values. Then, I compare products.
        dictprod = int(numpy.prod(templist))
        strprod = int(numpy.prod(strcounts))

    # If the product of the sequence STR counts and a persons STR counts are identical, change the yesvariable and the candidate counter value gets
    # passed to the names list so that the correct candidate is printed. Else, move onto the next candidate's STR count product and add one to the candidate counter.
        if (dictprod == strprod):
            yesvariable = 1
            realcand = candidate
        else:
            candidate = candidate + 1

    # Print name if there is a match, or else just print 'No Match'
    if yesvariable == 1:
        print(names[realcand])
    else:
        print("No match")