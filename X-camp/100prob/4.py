def log(s):
#    print(s)
    pass

def sort(nums):
    res = []
    res.append(nums[0])
    log(f"res = {res}")
    if nums[1] >= nums[0]:
        res.append(nums[1])
    else:
        res.insert(0, nums[1])
    log(f"second res = {res}")

    for i in range(2, len(nums)):
        for j in range(len(res) - 1, -1, -1):
            log("run")
            log(f"nums[i] = {nums[i]}, res[j] = {res[j]}")
            if nums[i] >= res[j]:
                res.insert(j + 1, nums[i])
                log(f"loop res = {res}")
                break
            if j == 0:
                res.insert(0, nums[i])
                log(f"first res = {res}]")

    return res

def main():
    temp = input()
    nums = input().split()
    for i in range(len(nums)):
        nums[i] = int(nums[i])
    nums = sort(nums)

    for i in range(len(nums)):
        nums[i] = str(nums[i])
    
    return " ".join(nums)

print(main())

#insertion sort is used to find the place for the number so the order can be made