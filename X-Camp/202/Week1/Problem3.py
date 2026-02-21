def getgrid(numofrows):

    status = {}
    y = 0

    while y < numofrows:

        templist2 = list(input().strip())
        
        if templist2 == []:

            continue

        for x in range(len(templist2)):

            if templist2[x] == "#":

                status.update({str(x) + ", " + str(y) : "wall"})

            elif templist2[x] == ".":

                status.update({str(x) + ", " + str(y) : "to be visited"})

        y += 1

    return status

def findsquares(x, y, coordinates, height, width):

    squares = 0

    if coordinates[str(x) + ", " + str(y)] == "to be visited":

        squares += 1
        coordinates[str(x) + ", " + str(y)] = "visited"

        if x > 0:

            squares += findsquares(x - 1, y, coordinates, height, width)

        if x < width - 1:

            squares += findsquares(x + 1, y, coordinates, height, width)

        if y > 0:

            squares += findsquares(x, y - 1, coordinates, height, width)

        if y < height - 1:

            squares += findsquares(x, y + 1, coordinates, height, width)
 
    return squares

def main():

    height, width = input().strip().split(" ")
    height = int(height)
    width = int(width)
    status = getgrid(height)
    blocksizes = []

    for y in range(height):

        for x in range(width):

            if status[str(x) + ", " + str(y)] == "to be visited":

                blocksizes.append(findsquares(x, y, status, height, width))

    return len(blocksizes)

print(main())