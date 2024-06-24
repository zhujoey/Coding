def log(s):

    print(s)
    pass

def fibb(n):

    if n == 0:

        return 1

    elif n == 1:

        return 2

    else:

        return fibb(n - 1) + fibb(n - 2)

def decode(sentence):

    key = sentence[0]
    keynum = ord(sentence[0]) - 97
    nums = []

    for i in range(2, len(sentence)):

        nums.append(str(ord(sentence[i]) + (keynum + fibb(i - 2)) % 26 + 97))

    return nums

def main():

    sentence = input()
    return " ".join(decode(sentence))

for i in range(5):

    print(main())