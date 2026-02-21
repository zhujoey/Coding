from math import sqrt


def log(s):
    print(s)
    pass

def isprime(num):
    for i in range(2, int(sqrt(num)) + 1):
        if num % i == 0:
            return False
    return True

def primefactors(num):
    factors = {1}
    for i in range(2, int(sqrt(num)) + 1):
        if num % i == 0:
            if isprime(i) == True:
                factors.add(i)
            
            if isprime(num / i) == True:
                factors.add(num / i)

    return len(factors) - 1
        

def main():
    res = []
    temp = int(input())
    for i in range(temp):
        res.append(str(primefactors(int(input()))))
    return '''
'''.join(res)
    

print(main())