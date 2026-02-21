def log(s):
    print(s)
    pass

def counttower(num):
    return 2 ** num - 1

def steps(disks, dep, arr, leftover):
    if disks == 1:
        print(str(dep) + "->" + str(arr))
    else:
        steps(disks - 1, dep, leftover, arr)
        print(str(dep) + "->" + str(arr))
        steps(disks - 1, leftover, arr, dep)

def main():
    num = int(input())
    steps(num, 1, 3, 2)
    print("tot=" + str(counttower(num)))

main()