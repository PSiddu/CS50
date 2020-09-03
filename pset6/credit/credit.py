# Counter variable for the main while loop
intcheck = 0

# Try-Catch statement to convert user input to an integer
def RepresentsInt(s):
    try:
        int(s)
        return True
    except ValueError:
        return False

# Program will keep running until it recieves a valid credit card number
while(intcheck == 0):
    userinput = (input("Number: "))

    # If the input wasn't even an integer, return INVALID
    if RepresentsInt(userinput) == False:
        print("INVALID")
    else:
        stringinput = str(userinput)
        stringinput = stringinput[::-1]
        intlist = [int(x) for x in stringinput]
        counter = 0
        doubleeveryotherlist = list()
        doubleplaceholder = 0

        # Implementing Luhn's Algorithm
        for x in intlist:
            counter = counter + 1
            if counter % 2 == 0:
                doubleplaceholder = x*2
                if doubleplaceholder >= 10:
                    doubleplaceholder = doubleplaceholder - 9
                doubleeveryotherlist.append(doubleplaceholder)
            else:
                doubleeveryotherlist.append(x)
        digitstotal = sum(doubleeveryotherlist)

        if (digitstotal % 10) == 0:
            stringinput = stringinput[::-1]
            firstwo = stringinput[:2]
            firstone = stringinput[:1]

            # Start of length checks after running Luhn's algorithm
            if firstwo == "34" or firstwo == "37":
                if len(stringinput) == 15:
                    print("AMEX")
                    intcheck = 1
                else:
                    print("INVALID")
            elif firstwo == "51" or firstwo == "52" or firstwo == "53" or firstwo == "54" or firstwo == "55" \
                    or firstwo == "22":
                if len(stringinput) == 16:
                    print("MASTERCARD")
                    intcheck = 1
                else:
                    print("INVALID")
            elif firstone == "4":
                if len(stringinput) == 13 or len(stringinput) == 16:
                    print("VISA")
                    intcheck = 1
                else:
                    print("INVALID")
            else:
                print("INVALID")
        else:
            print("INVALID")