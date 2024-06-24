def log(s):
    print(s)
    pass

def counttower(num):
    return 2 ** num - 1

def main():
    num = int(input())
    return counttower(num)

print(main())