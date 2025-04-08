def three_numbers(n):
    a = n // 100
    b = n - a * 100
    c = b // 10
    # d = n - a * 100 - c * 10
    c = n % 100 // 10
    d = n % 10
    if n == a ** 3 + c ** 3 + d ** 3:
        print(n)      



for i in range(100, 1000):
    three_numbers(i)
