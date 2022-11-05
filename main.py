def whatsNext():
    print("\nWould you like to continue")
    print("1. Yes\n2. No")
    while True:
        try:
            #Getting the first term, common difference, and number of terms to display from the user
            choice = int(input("Enter Your answer here: "))

        # When the user inputs something that is not a number
        except ValueError:
            print("Sorry, I didn't understand that.\n")
            arith()
        else:
            if choice == 1 or choice == 2:
                if choice == 1:
                    main()
                else:
                    print("Thank You for stopping by!\nHave a nice day")
                    exit()
            else:
                print("Please select either 1 or 2")

def arith():
    while True:
        try:
            #Getting the first term, common difference, and number of terms to display from the user
            first = int(input("First term of the sequence: "))
            cd = int(input("Common difference: "))
            no = int(input("Number of terms to display: "))

        # When the user inputs something that is not a number
        except ValueError:
            print("Sorry, I didn't understand that.\n")
            arith()
        else:
            #Inputting the first number into the arithmetic progressions array
            ap = []
            ap.insert(1, first)
            #Finding out the remaining numbers
            i = 2
            while i <= no:
                #Calculating the next number in the sequence
                nextNo = first + (cd*(i-1))
                #Storing that number into an array
                ap.insert(i, nextNo)
                i = i + 1


            print(ap)
            whatsNext()

def geo():
    while True:
        try:
            # Getting the first term, common difference, and number of terms to display from the user
            first = int(input("First term of the sequence: "))
            cr = int(input("Common Ratio: "))
            no = int(input("Number of terms to display: "))

        # When the user inputs something that is not a number
        except ValueError:
            print("Sorry, I didn't understand that.\n")
            arith()
        else:
            # Inputting the first number into the arithmetic progressions list
            gp = []
            gp.insert(1, first)
            # Finding out the remaining numbers
            i = 2
            while i <= no:
                # Calculating the next number in the sequence
                nextNo = first*(cr**(i-1))
                # Storing that number into the list
                gp.insert(i, nextNo)
                i = i + 1

            #Printing out the progression
            print(gp)
            whatsNext()

def main():
    #Asking the user which progression they would like to pick
    print("Choose the Type of Progression you would like to display")
    print("1. Arithmetic Progression")
    print("2. Geometric Progression\n")

    while True:
        try:
            progr = int(input("Your Answer Here:"))
        #When the user inputs something that is not a number
        except ValueError:
            print("Sorry, I didn't understand that.\n")
            main()
        else:
            #Deciding which progression basing on the user's input
            if progr == 1 or progr == 2:
                if (progr == 1):
                    print("\nArithmetic Progression")
                    arith()
                else:
                    print("\nGeometric Progression")
                    geo()
            else:
                print("Please select either option 1 or 2")
                main()

#Calling the main function
main()

