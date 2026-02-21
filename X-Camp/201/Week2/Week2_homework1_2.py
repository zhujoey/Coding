#A

def log(message):
    #print(message)
    pass

def getgrid(numofrows):

    status = {}

    for y in range(numofrows):

        templist2 = input().strip().split(" ")

        for x in range(len(templist2)):

            if templist2[x] == "0":

                status.update({str(x) + ", " + str(y) : "to be visited"})

            elif templist2[x] == "1":

                status.update({str(x) + ", " + str(y) : "wall"})

    log(f"status = {status}")
    return status

def findsquares(x, y, coordinates, numofrows):

    squares = 0

    if coordinates[str(x) + ", " + str(y)] == "to be visited":

        squares += 1
        coordinates[str(x) + ", " + str(y)] = "visited"

        if x > 0 and y > 0:

            squares += findsquares(x - 1, y - 1, coordinates, numofrows)
            log(f"case 1 {squares}")

        if x < numofrows - 1 and y < numofrows - 1:

            squares += findsquares(x + 1, y + 1, coordinates, numofrows)
            log(f"case 2 {squares}")

        if y > 0:

            squares += findsquares(x, y - 1, coordinates, numofrows)
            log(f"case 3 {squares}")

        if y < numofrows - 1:

            squares += findsquares(x, y + 1, coordinates, numofrows)
            log(f"case 4 {squares}")

    return squares

def main():
    # 1. Use as little global variables as possible
    # 2. Use return to get local variables
    # 3. Add parameters
    # 4. Give meaning to log
    # 5. Use main and don't put code outside
    # 6. Be careful of indent
    size, startx, starty = input().strip().split(" ")
    log(f"size = {size}, startx = {startx}, starty = {starty}")
    squares = findsquares(int(startx), int(starty), getgrid(int(size)), int(size))
    log(f"squares = {squares}")
    print(squares)

#main()

#B

def findsquares(x, y, coordinates, height, width):

    squares = 0
    log(f"x = {x} y = {y}")
    if coordinates[str(x) + ", " + str(y)] == "to be visited":

        squares += 1
        coordinates[str(x) + ", " + str(y)] = "visited"

        if x > 0:

            squares += findsquares(x - 1, y, coordinates, height, width)
            #log(f"case 1 {squares}")
            log(f"squares = {squares} case 1")

        if x < width - 1:

            squares += findsquares(x + 1, y, coordinates, height, width)
            #log(f"case 2 {squares}")
            log(f"squares = {squares} case 2")

        if y > 0:

            squares += findsquares(x, y - 1, coordinates, height, width)
            #log(f"case 3 {squares}")
            log(f"squares = {squares} case 3")
            
        if y < height - 1:

            squares += findsquares(x, y + 1, coordinates, height, width)
            #log(f"case 4 {squares}")
            log(f"squares = {squares} case 4")

    return squares

def main():
    # 1. Use as little global variables as possible
    # 2. Use return to get local variables
    # 3. Add parameters
    # 4. Give meaning to log
    # 5. Use main and don't put code outside
    # 6. Be careful of indent
    status = {}
    startx = 0
    starty = 0
    width, height = input().strip().split(" ")

    for y in range(int(height)):
        
        #templist2 = input().strip().split()
        templist = [*input()]

        for x in range(len(templist)):

            if templist[x] == ".":

                status.update({str(x) + ", " + str(y) : "to be visited"})

            elif templist[x] == "#":

                status.update({str(x) + ", " + str(y) : "wall"})
                
            elif templist[x] == "@":
                status.update({str(x) + ", " + str(y) : "to be visited"})

                startx = x
                starty = y

    if input().strip().split(" ") == ["0", "0"]:

        return findsquares(int(startx), int(starty), status, int(height), int(width))

print(main(), end='')