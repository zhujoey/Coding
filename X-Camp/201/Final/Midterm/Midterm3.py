allnums = []
sums1 = []
sums2 = []
height, width = input().strip().split(" ")


def log(message):

    print(message)
    pass

def toint(str):
    
    try:
        return int(str)
    
    except:
        return None

def getnums():
    
    for i in range(int(height)):
        
        temprow = list(input().strip())
        row = []
        
        for j in temprow:
                   
            if j == "*":

                j = 0
                row.append(int(j))
            
            elif j == "#":
                
                j = "wall"
                row.append(j)
            
            else:
                
                row.append(int(j))
        
        allnums.append(row)

getnums()
        
def findsum():
    
    global sums1
    global sums2

    for i in range(len(allnums)):
        
        if i % 2 == 0:
            
            sums1 = []
            
        elif i % 2 == 1:
            
            sums2 = []
        
        for j in range(len(allnums[i])):

            if i % 2 == 0:
                
                if i == 0:
                    
                    sums1.append(allnums[i][j])

                elif j == 0:

                    if sums2[j]  != "wall":
                        sums1.append(allnums[i][j] + sums2[j])

                else:

                    sums1.append(allnums[i][j] + max(sums2[j - 1], sums2[i - 1], sums2[j]))

            elif i % 2 == 1:               

                if j == 0:

                    if sums1[j] != "wall":
                        
                        sums2.append(allnums[i][j] + sums1[j])

                else:

                    sums2.append(allnums[i][j] + max(sums1[j - 1], sums1[j]))

findsum()

def largestnum(templist):

    max = 0

    for i in range(len(templist)):

        if int(templist[i]) > int(max):

            max = int(templist[i])
    
    return max
            

def result():

    if len(allnums) % 2 == 0:
        
        return largestnum(sums2)
    
    if len(allnums) % 2 == 1:
        
        return largestnum(sums1)

print(result())