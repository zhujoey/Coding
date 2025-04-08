def xyyx(a):
    x = 1
    y = 1
    '''
    def b():
        if a % 2 == 0:
            a // 2
            return a
        elif a % 2 == 1:
            a // 2 + (x + y)
            return a
            '''
    for i in range(1, (a + 1) // 2):
        y = x + y
        x = y + x
    if a % 2 == 1:
        return y
    elif a % 2 == 0:
        return x
for a in range(1, 100):
    print(xyyx(a))
