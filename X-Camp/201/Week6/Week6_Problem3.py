def log(message):
    print(message)
    pass

def getgrid(numofrows):

    status = {}
    y = 0

    while y < numofrows:

        templist = input().strip().split()
        
        if templist == []:

            continue

        for x in range(len(templist)):

            status.update({str(x) + ", " + str(y) : templist[x]})

        y += 1

    return status

def findsquares(x, y, status, height, width):

    squares = 0
    squares += 1

    if x > 0:

        if status[f"{x - 1}, {y}"] < status[f"{x}, {y}"]:

            squares += findsquares(x - 1, y, status, height, width)

    if x < width - 1:

        if status[f"{x + 1}, {y}"] < status[f"{x}, {y}"]:

            squares += findsquares(x + 1, y, status, height, width)

    if y > 0:

        if status[f"{x}, {y - 1}"] < status[f"{x}, {y}"]:

            squares += findsquares(x, y - 1, status, height, width)

    if y < height - 1:

        if status[f"{x}, {y + 1}"] < status[f"{x}, {y}"]:

            squares += findsquares(x, y + 1, status, height, width)

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
    status = getgrid(height)
    paths = []

    for y in range(height):

        for x in range(width):

                paths.append(findsquares(x, y, status, height, width))
                log(f"paths = {paths}")

    return max(paths)

print(main())