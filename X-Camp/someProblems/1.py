def log(s):
    print(s)
    pass

def printnum(lines):

    for i in range(1, int(lines * (lines + 1) / 2) + 1):
        for j in range(4 - len(str(i))):
            print(" ", end = "")

        x = 0
        while int(x * (x + 1) / 2) <= i:
            if int(x * (x + 1) / 2) == i:
                print(i)
                x = -1
                break
            x += 1

        if x == -1:
            continue
        
        else:
            print(i, end = "")


def main():
    lines = int(input())
    printnum(lines)

main()