def log(message):
    print(message)
    pass

def getgrid(numofrows):

    status = []

    for y in range(numofrows):

        templist2 = input().strip().split(" ")

        for x in range(len(templist2)):

            status.append(templist2[x])

    return status

def main():

    size, startx, starty = input().strip().split(" ")

print(main())