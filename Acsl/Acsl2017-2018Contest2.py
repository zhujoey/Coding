def log(s):

    print(s)
    pass

def findspots(expression):

    spots = []

    for i in range(len(expression)):

        j = i + 1

        if expression[i] == "(":

            while j <= len(expression):

                try:

                    int(expression[j])

                    if j >= i + 3:

                        spots.append(str(j + 2))

                except:

                    pass

                j += 1

        elif expression[i] == ")":

            while j >= 1:

                try:

                    int(expression[j])

                    if j <= i - 1:

                        spots.append(str(j - 1))

                except:

                    pass

                j = j - 1

    return spots

def main():

    expression = input()

    return ", ".join(findspots(expression))

print(main())