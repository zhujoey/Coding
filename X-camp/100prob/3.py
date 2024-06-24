def log(s):
    print(s)
    pass

def getnums(nums):
    nums = sorted(nums)
    res = []

    for i in range(len(nums) // 2):
        res.append(str(nums[-(i + 1)]))
        res.append(str(nums[i]))

    if len(nums) % 2 == 1:
        res.append(str(nums[len(nums) // 2]))

    return res

def main():
    temp = int(input())
    nums = []
    for i in range(temp):
        nums.append(int(input()))
    
    return '''
'''.join(getnums(nums))

print(main())