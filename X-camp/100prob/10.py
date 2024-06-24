def log(s):
    print(s)
    pass

def countones(string):
    res = 0
    for i in string:
        if i == "1":
            res += 1

    return res

def main():
    string = list(input())
    return countones(string)
    
print(main())