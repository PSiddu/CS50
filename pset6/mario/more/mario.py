# Condition variable and while loop for repeated asking the user for a valid integer until one is received
cond = 0
height = 0
while (cond == 0):
    try:
        height = int(input("Height: "))
    except ValueError:
        cond = 0
    if(height >= 1 and height <= 8):
        cond = 1

# Counter variable that keeps track of the number of spaces needed on each line to form a pyramid shape
counter = height - 1

# Counter variable that keeps track of the number of hashes needed on each line to form a pyramid shape
hashes = height - counter

# While loop for printing the pyramid in the correct order
while (counter > -1):
    for i in range(0, counter):
        print(" ", end ="")

    for i in range(0, hashes):
        print("#", end ="")

    print("  ", end ="")

    for i in range(0, hashes):
        print("#", end ="")

    counter = counter - 1
    hashes = height - counter
    print("")