'''
def count2inoctal(s):
    
    res = 0
    values = {'0' : 0, '1' : 1, '2' : 2, '3' : 3, '4' : 4, '5' : 5, '6' : 6, '7' : 7, '8' : 8, '9' : 9, 'A' : 10, 'B' : 11, 'C' : 12, 'D' : 13, 'E' : 14, 'F' : 15}
    numof2 = 0
    
    for c in s:
        res = res * 16 + values[c]
        
    s = res
    rem = []
    res = ""
    
    while int(s) > 0:
        
        rem.append(int(s) % 8)
        s = int(s) // 8
    
    for i in range(0, len(rem)):
        
        if rem[i] == 2:
            numof2 += 1
            
    return numof2

#print(count2inoctal("508"))
#print(count2inoctal("88A"))
#print(count2inoctal("195"))
#print(count2inoctal("348A"))
#print(count2inoctal("1050"))

def yeartosixteenth(s):

    list = []
    res = 0
    
    for i in range(3):
            
        if i == 0:
            res == int(s[0])
        if i == 1:
            res == int(s[2]) * 10 + int(s[3])
        if i == 2:
            res == int(s[5]) * 1000 + int(s[6]) * 100 + int(s[7]) * 10 + int(s[8])
        
        for c in s:
            res = res * 16 + int(c)
            
        list.append(res)
    
    return str(list[0]) + "/" + str(list[1]) + "/" + str(list[2])
print(yeartosixteenth("5/23/2020"))
'''

input = input().split()

def changenumber(n):

    position = int(input[1])
    place = -position
    transition = int(input[2])
    n = list(str(n))
#using a list is easier to use than a string
#strings are not allowed to change
    if int(n[place]) >= 0 and int(n[place]) <= 4:
#replace cannot be used to change specific parts of string
        n[place] = str((int(n[place]) + transition) % 10)

        for i in range(1, position):
            n[-i] = "0"

    elif int(n[place]) >= 5 and int(n[place]) <= 9:

        n[place] = str(abs(int(n[place]) - transition))
        n[place] = n[place][0]

        for i in range(1, position):

            n[-i] = "0"

    return ''.join(n)

print(changenumber(int(input[0])))