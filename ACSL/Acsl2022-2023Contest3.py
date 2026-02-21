def log(s):
    print(s)
    pass

def listbyvalue(word):
    nums = []
    sortedword = []
    for i in range(len(word)):
        if i == 0:
            sortedword.append(word[0])
            nums.append(0)
        else:
            sortedword.append(word[i])
            sortedword = sorted(sortedword)
            index = sortedword.index(word[i])
            if index == 0:
                nums.insert(index, nums[index] + 1)
            elif index == len(nums):
                nums.insert(index, nums[len(nums) - 1] + 1)
            else:
                nums.insert(index, max(nums[index - 1], nums[index]) + 1)

    numtoword = list(zip(*[nums, sortedword]))
    numtoword = sorted(numtoword)
    resword = []

    for i in numtoword:
        resword.append(i[1])

    return "".join(resword)

def main():
    word = input()
    return listbyvalue(word)

print(main())

#Write it down
#Dictionary has no order
#Use tuple