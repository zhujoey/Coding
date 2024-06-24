#D
allnums = []
sums1 = []
sums2 = []

def getnums():
    
    for i in range(int(input())):
        
        temprow = input().split()
        row = []
        
        for j in temprow:
            
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

            if i == 0:

                sums1.append(allnums[i][j])

            elif i % 2 == 0:

                if j == len(allnums[i]) - 1:

                    sums1.append(allnums[i][j] + sums2[j - 1])

                elif j == 0:

                    sums1.append(allnums[i][j] + sums2[j])

                else:

                    sums1.append(allnums[i][j] + max(sums2[j - 1], sums2[j]))

            elif i % 2 == 1:               

                if j == len(allnums[i]) - 1:

                    sums2.append(allnums[i][j] + sums1[j - 1])
           
                elif j == 0:
                    
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