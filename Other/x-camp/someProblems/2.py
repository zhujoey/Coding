def log(s):
    print(s)
    pass

def countnums(n, x):
    count = 0
    for i in range(1, n + 1):
        i = list(str(i))
        for j in i:
            if int(j) == x:
                count += 1
    
    return count

def main():
    nums = input().split()
    n = int(nums[0])
    x = int(nums[1])
    return countnums(n , x)

print(main())