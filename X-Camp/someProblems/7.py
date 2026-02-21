from math import sqrt


def log(s):
    print(s)
    pass

def isprime(num):
    for i in range(2, int(sqrt(num)) + 1):
        if num % i == 0:
            return False
    return True

def theory(num):
    primenums = []
    for i in range(2, num):
        if isprime(i) == True and isprime(num - i) == True:
            primenums.append(i)
            primenums.append(num - i)
            break

    return primenums

def main():
    num = int(input())
    res = theory(num)
    return str(num) + "=" + str(res[0]) + "+" + str(res[1])
print(main())