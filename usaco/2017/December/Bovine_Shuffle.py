def log(s):
    print(s)
    pass
    
def findlastpos(movesequence, currentpos):
    for i in range(len(movesequence)):
        if int(movesequence[i]) == currentpos:
            return int(i)


def findcoworder(movesequence, cowids):
    cowinitialids = [0, 1, 2, 3, 4]
    for i in range(len(cowids)):
        cowinitialids[int(findlastpos(movesequence,(findlastpos(movesequence, findlastpos(movesequence, int(i) + 1) + 1) + 1)))] = str(cowids[i])
    
    return cowinitialids

def main():

    temp = input().split()
    movesequence = input().split()
    cowids = input().split()
    return '''
'''.join(findcoworder(movesequence, cowids))

print(main())