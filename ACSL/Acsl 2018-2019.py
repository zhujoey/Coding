'''
#1

def octal(n):
    
    int(n)
    rem = []
    res = ""
    
    if n == 0:
        return "0"
    
    if n < 0:
        return "-" + octal(-n)
    
    while n > 0:
        
        rem.append(n % 8)
        n = n // 8
        
    rem.reverse()
    
    for i in range(0, len(rem)):
        res = res + str(rem[i])
    
    return res

#print(octal(2018))

#2
def count1and0(n):
    
#    res = []
    count = 0
        
    for i in range(1, n + 1):
        
#        temp = i
        one = 0
        zero = 0
#        list = []
    
        while i > 0:
            
            if i % 2 == 1:
                one += 1
            elif i % 2 == 0:
                zero += 1
            i = i // 2
            
        if one == zero:
#            print(temp)
            count += 1
    
    return count
            
#        list.append(one)
#        list.append(zero)
            
#        res.append(list)
        
#    for i in range(len(list) + 1):
        
                    
#    return res

#print(count1and0(1000000))

#3
def f(n):

    if n > 5:
        return f(n - 5) + 1

    if n == 5:
        return 7

    if n < 5:
        return f(n + 3) - 2

#    return f(n)

#print(f(18))

#4
import math

def f(x):

    if x % 2 == 0:
        return math.floor(x / 2) + 1
    
    elif x % 2 == 1:
        return math.floor(x / 3) - 2

print(f(f(f(f(24)))))
'''

import math

def digitreassembly(a, b, c, d, e):
    
    a = str(a)
    res1 = len(a)
    
    res2 = 0    
    b = str(b)
    for i in range(len(b)):
        res2 += int(b[i])
    
    res3 = 0
    c = str(c)
    for i in range(0, len(c), 2):
        res3 += int(c[i])
    
    res4 = 0
    d = str(d)
    for i in d:
        if i == "4":
            res4 += 1
    
    res5 = 0
    e = str(e)
    if len(e) % 2 == 0:
        res5 = int(e[len(e) // 2 - 1])
    elif len(e) % 2 == 1:
        res5 = int(e[(len(e) - 1) // 2])
    
    results = [str(res1), str(res2), str(res3), str(res4), str(res5)]
    return '''
'''.join(results)
    

inputa = input()
inputb = input()
inputc = input()
inputd = input()
inpute = input()

print(digitreassembly(inputa, inputb, inputc, inputd, inpute))