#input as little variables here as possible
#put as much code as possible into functions
input = input().split()
rows = int(input[2])
lastrow = []
nums = int((rows + 1) * rows / 2)
#be carefule with int
def digitsum(n):
    
    while int(n) >= 10:
        
        n = str(n)
        temp = 0
        
        for i in range(len(n)):
            
            temp += int(n[i])
#use longer variable names that make more sense
            n = temp
        
    return n

def getnumbers():
    
    start = int(input[0])
    delta = int(input[1])
    
    for i in range(nums):
#dividing gives float so int the value
        if nums - i <= rows:
            
            lastrow.append(start)
#append the number before adding because you will skip the first or the last number            
        start += delta
        start = digitsum(start)
#digitsum comes after adding the delta
def getsum():
    
    getnumbers()
    sum = 0
    
    for i in range(len(lastrow)):
        sum += lastrow[i]

    return sum

print(getsum())