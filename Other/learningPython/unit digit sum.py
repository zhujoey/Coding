def digit_sum(x):
    res = []
    while x > 0:
        res.append(x % 10)
        x = x // 10
    return sum(res)
print(digit_sum())
