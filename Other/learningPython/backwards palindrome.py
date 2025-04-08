def add_to_palindrome(x):
    digits = []
    y = 0
    c =0
    while x > 0:
        digits.append(x % 10)
        x = x // 10
    while digits:
        y = y * 10 + digits[c]
        del digits[c]
    return y
print(add_to_palindrome(456))
