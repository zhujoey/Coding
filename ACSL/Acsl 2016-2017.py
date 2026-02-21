'''
#1
def f(x):
    y = 0
    if x > 1:
        y = f(x - 1) + 2
    elif x == 1:
        y = 4
    return y
#print(f(4))

#2
def g(x):
    y = 0
    if x <= 10:
        y = g(2 * x - 1) + 1
    elif x > 10:
        y = x + 2
    return y
#print(g(4))

#3
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

#print(octal(1000))

def sixteenth(s):

    res = 0
    
    for c in s:
        res = res * 16 + int(c)

    return res

print(sixteenth("123"))

#ACSL AGRAM
def agram(s):

    case1value = 0
    index = 4
    outcome = 0
    case2value = 9
    temp = 9

    while index < len(s):

        if s[index + 2] == s[2] and int(s[index]) > int(s[0]) and int(s[index]) < temp:

            case1value = int(s[index])
            temp = int(s[index])
            outcome = 1

        elif s[index + 2] == s[2]:

            if int(s[index]) <= case2value:
                case2value = int(s[index])
            
            if outcome == 0:
                outcome = 2

        index += 4

    if outcome == 0:
        return None

    if outcome == 1:
        return str(case1value), s[2]

    elif outcome == 2:
        return str(case2value), s[2]

#print(agram("5,D,2,D,6,H,9,D,9,S,6,H"))
#print(agram("4,C,1,C,6,C,7,H,5,S,4,D"))
#print(agram("3,D,4,H,5,C,6,S,2,D,1,D"))
#print(agram("9,S,8,H,7,C,7,D,9,H,3,H"))
#print(agram("1,C,1,D,9,H,8,S,9,S,7,C"))
#print(agram("4,S,2,S,5,S,6,S,8,S,9,S"))
#print(agram("7,H,3,S,3,H,3,D,3,C,2,H"))
#print(agram("9,D,3,C,5,H,1,S,7,D,9,S"))
#print(agram("6,C,1,S,2,H,7,S,8,D,9,H"))
#print(agram("1,D,2,S,3,D,4,S,2,H,2,C"))
#print(agram("3,D,2,S,1,D,4,S 2,D,2,C"))
'''
input = input()

def agram(sample):

    sample = sample.split(",")
    suit = sample[1]
    number = sample[0]
    temp = []

    for i in range(3, len(sample), 2):
        if sample[i] == suit:
            temp.append(sample[i - 1])

    if len(temp) == 0:
        return "NONE"

    mid = 10

    for i in range(len(temp)):
        if int(temp[i]) > int(number) and int(temp[i]) < int(mid):
            mid = temp[i]

    if mid == 10:
        for i in range(len(temp)):
            if int(temp[i]) < int(mid):
                mid = temp[i]

    return int(mid), suit

print(agram(input))