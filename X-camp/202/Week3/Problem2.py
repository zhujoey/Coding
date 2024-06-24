def log(s):
    print(s)
    pass

def countperson(numofpeople, num):
    numofpeople = int(numofpeople)
    num = int(num)
    people = []
    order = []

    for i in range(numofpeople):
        people.append(i + 1)

    i = 0
    while len(people) > 0:
        i = (i + num) % len(people) - 1
        order.append(str(people[i]))
        del people[i]

    return " ".join(order)

def main():
    templist = input().split()
    numofpeople = templist[0]
    num = templist[1]
    return countperson(numofpeople, num)

print(main())