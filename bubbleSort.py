#This program was created by Arman Nadjarian on 12/17/2020 at 10:00 AM

array = [] #this will hold our numbers to be sorted

def printer():
    for i in array:
        print(str(i) + ": ", end = '')
        if i == 0:
            print("zero", end = '')
        elif i < 0:
            print("less than zero", end = '')
        else:
            for _ in range(0, i):
                print(" = ", end = '')
        print("")

def bubbleSort(array):
    length = len(array)
    for i in range(length):
        for j in range(length-i-1):
            if array[j] > array[j+1]:
                array[j], array[j+1] = array[j + 1], array[j]

def tryConvertToInt(userInput):
    try:
        userInput = int(userInput)        
        return userInput
    except ValueError:
        return False


#program starts here

print("\nLet's Run a Sorting Algorithm...")

doneAsking = False
while doneAsking != True:
    print("Please enter an integer value (Or enter any non-integer value to see the sorted results): ", end = '')
    value = input()
    if value == '0': #in the case that the value is zero. The algorithm was buggy in the case of 0, so this check had to be hard coded in
        value = 0
        array.append(value)
        continue
    else:
        result = tryConvertToInt(value)
        if result == False:
            print("Non-Integer Value Entered. Let's see the results...\n")
            doneAsking = True
        else:
            array.append(result)




print("Before the Sort:")
printer()

print("\nAfter the Bubble Sort:")
bubbleSort(array)
printer()
