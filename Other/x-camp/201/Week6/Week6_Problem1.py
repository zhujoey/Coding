def log(message):
    print(message)
    pass

def getgrid(numofrows):

    status = {}
    y = 0

    while y < numofrows:

        templist2 = list(input().strip())
        
        if templist2 == []:

            continue

        for x in range(len(templist2)):

            if templist2[x] == "0":

                status.update({str(x) + ", " + str(y) : "wall"})

            elif templist2[x] == "1":

                status.update({str(x) + ", " + str(y) : "to be visited"})

        y += 1
    log(f"status = {status}")
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

    # 1. Use as little global variables as possible
    # 2. Use return to get local variables
    # 3. Add parameters
    # 4. Give meaning to log
    # 5. Use main and don't put code outside
    # 6. Be careful of indent
    # 7. Use while if input is weird
    # 8. Be careful of recursion going out of range
    # 9. Look at the input and adapt
    # 10. If one thing is changed change everything related to it

    height, width = input().strip().split(" ")
    height = int(height)
    width = int(width)
    log(f"width = {width}")
    status = getgrid(height)
    blocksizes = []

    for y in range(height):

        for x in range(width):

            if status[str(x) + ", " + str(y)] == "to be visited":
                log(f"main: x = {x}, y = {y}")

                blocksizes.append(findsquares(x, y, status, height, width))

    return max(blocksizes)

print(main())