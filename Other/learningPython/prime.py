

def is_prime(n):
    global nop, noc
    for i in range(2, n):
        if n % i == 0:
            noc = noc + 1
            print('%d is a composite number.' % n)
            break
    else:
        nop = nop + 1
        print('%d is a prime.' % n)

nop = 0
noc = 0
for s in range(100, 1001):
    is_prime(s)

print('There are %s prime numbers.' % nop)
print('There are %s composite numbers.' % noc)
