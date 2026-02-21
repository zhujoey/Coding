def log(msg):

    print(msg)
    pass

def breaknum(strinput):

    finalnums = []
    nums = []
    strinput = list(strinput)

    for i in strinput:

        nums.append(int(i))
    
    finalnums.append(nums[0])
    i = 1
    j = 0

    while i <= len(nums) - 1:

        indexnum = 0
        digitsadded = 0

        while True:

            try:
                indexnum = indexnum * 10 + nums[i + digitsadded]
            
            except:
                break

            if indexnum > finalnums[j]:
                break

            digitsadded += 1

        finalnums.append(indexnum)

        i = i + digitsadded + 1
        j += 1

    return finalnums

def main():

    finalnums = breaknum(input())
    result = []
    try:
        if finalnums[-1] <= finalnums[-2]:

            del finalnums[-1]
    except:
        pass

    for i in finalnums:

        result.append(str(i))

    result = " ".join(result)

    return result

for i in range(5):

    print(main())