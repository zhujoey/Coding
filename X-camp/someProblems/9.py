def log(s):
    print(s)
    pass

def merge(list1, list2):
    res = []
    i = 0
    j = 0
    while i < len(list1) and j < len(list2):
        if list1[i] >= list2[j]:
            res.append(str(list1[i]))
            i += 1
        else:
            res.append(str(list2[j]))
            j += 1

    if i == len(list1) and j < len(list2):
        for i in range(j, len(list2)):
            res.append(str(list2[i]))
    elif j == len(list2) and i < len(list1):
        for i in range(i, len(list1)):
            res.append(str(list1[i]))
    
    return res

def main():
    list1 = input().split()
    del(list1[-1])
    list2 = input().split()
    del(list2[-1])

    for i in range(len(list1)):
        list1[i] = int(list1[i])
    for i in range(len(list2)):
        list2[i] = int(list2[i])
    return " ".join(merge(list1, list2))

print(main())