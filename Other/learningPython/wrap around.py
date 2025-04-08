first = [1, 2, 3, 4, 5]
second = [6, 7, 8, 9, 10]
third = [11, 12 ,13, 14, 15]
fourth = [16, 17, 18, 19, 20]
last = [21, 22, 23, 24, 25, 26]
def which_letter(c):
    res = ord(c) - ord('A') + 1
    if res in first:
        res = res * 2
    elif res in second:
        res = res % 3 * 5
    elif res in third:
        res = res // 4 * 8
    elif res in fourth:
        res = (res // 10 + res % 10) * 10
        if res % 26 == 0:
            res = 26
        else:
            res = res % 26
    elif res in last:
        factors = []
        for n in range(1, res):
            if res % n == 0:
                factors.append(n)
        res = factors[-1]
        res = res * 12
        if res % 26 == 0:
            res = 26
        else:
            res = res % 26
    res = chr(res - 1 + ord('A'))
    return res
print(which_letter('S'))
'''
print(which_letter('G'))
print(which_letter('Z'))
print(which_letter('T'))
print(which_letter('K'))
'''
