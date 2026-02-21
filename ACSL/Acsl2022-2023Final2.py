def log(s):
    print(s)
    pass

def sumsNotCommon(first, second, third):
    if third == "null":
        pass
    else:
        third = third.split()

def main():
    first = input().split()
    second = input().split()
    third = input()
    log(f"first = {first}, second = {second}, third = {third}")
    return sumsNotCommon(first, second, third)
print(main())