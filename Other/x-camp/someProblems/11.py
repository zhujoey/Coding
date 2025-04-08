def log(s):
    print(s)
    pass

def round(num):
    return int(int(input()) / 10 + 0.5) * 10

def main():
    num = int(input())
    return round(num)

print(main())