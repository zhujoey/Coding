def log(s):
    print(s)
    pass


def findnum(nums, target):

    numlist = sorted(nums)
    i = 0
    j = len(numlist) - 1

    while numlist[i] + numlist[j] != target:
        #log(f"i = {i}, j = {j}")
        if numlist[i] + numlist[j] < target:
            i = i + 1

        else:
            j = j - 1
    #log(f"i = {i}, j = {j}")
    
    x = -1
    y = -1

    for k in range(len(nums)):
        if numlist[i] == nums[k] and x == -1:
            x = k
        elif numlist[j] == nums[k] and y == -1:
            y = k
        #log(f"x = {x}, y = {y}, nums[k] = {nums[k]}")

    return [x, y]


def main():
    numlist = list(input())
    target = int(input())

    del numlist[0], numlist[-1]
    numlist = "".join(numlist)
    numlist = numlist.split(",")

    for i in range(len(numlist)):
        numlist[i] = int(numlist[i])

    return findnum(numlist, target)

print(main())