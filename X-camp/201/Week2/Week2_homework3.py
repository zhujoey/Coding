#B

def log(message):
    #print(message)
    pass

def findsquares(x, y, status, height, width, iteration):

    if status[str(x) + ", " + str(y)] == "to be visited":

        status[str(x) + ", " + str(y)] = iteration
    
    elif status[str(x) + ", " + str(y)] == "wall":
        
        status[str(x) + ", " + str(y)] = 0
        
        if y > 0:

            findsquares(x, y - 1, status, height, width, iteration + 1)

        if x > 0:

            findsquares(x - 1, y, status, height, width, iteration + 1)

        if x < width - 1:

            findsquares(x + 1, y, status, height, width, iteration + 1)
            
        if y < height - 1:

            findsquares(x, y + 1, status, height, width, iteration + 1)
    
    return status

def main():

    # 1. Use as little global variables as possible
    # 2. Use return to get local variables
    # 3. Add parameters
    # 4. Give meaning to log
    # 5. Use main and don't put code outside
    # 6. Be careful of indent

    status = {}
    width, height = input().strip().split(" ")

    for y in range(int(height)):
        
        #templist2 = input().strip().split()
        templist = [*input()]

        for x in range(len(templist)):

            if templist[x] == "0":

                status.update({str(x) + ", " + str(y) : "to be visited"})

            elif templist[x] == "1":

                status.update({str(x) + ", " + str(y) : "wall"})

    return findsquares(0, 0, status, int(height), int(width), 1)

print(main())