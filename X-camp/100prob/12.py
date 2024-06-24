def log(s):
    print(s)
    pass

def count(num):
    nums = []
    for i in range(1, num + 1):
        if i == 1:
            nums.append(1)
        elif i == 2:
            nums.append(2)
        elif i == 3:
            nums.append(4)
        else:
            nums.append(nums[i - 4] + nums[i - 2] + nums[i - 3])
    
    return nums[-1]
        

def main():
    num = int(input())
    return count(num) % 998244353

print(main())