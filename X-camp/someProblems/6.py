from re import L


def log(s):
    print(s)
    pass

def gcdlcm(num1, num2):

    for i in range(min(num1, num2), 0, -1):
        if num1 % i == 0 and num2 % i == 0:
            gcd = i
            break

    lcm = max(num1,num2)
    while True:
        if lcm % num1 == 0 and lcm % num2 == 0:
            break
        lcm += 1

    return [str(gcd), str(lcm)]
        

def main():
    temp = input().split()
    num1 = int(temp[0])
    num2 = int(temp[1])
    return '''
'''.join(gcdlcm(num1, num2))

print(main())