def log(s):
    #print(s)
    pass

def reverse(sample):
    temp = []
    for i in range(1, len(sample) + 1):
        temp.append(sample[-i])    
    return temp

def changedPositions(customers):
    changes = 0
    for i in range(1, len(customers) + 1):
        for j in range(len(customers)):
            log(f"j = {j} and customers[j] = {customers[j]} and i = {i}")
            if int(customers[j]) == int(i):
                log("run")
                temp = []
                for x in range(j + 1):
                    temp.append(customers[0])
                    log(f"temp = {temp}")
                    del(customers[0])

                if len(temp) > 1:
                    if len(temp) % 2 == 1:
                        changes += len(temp) - 1
                        log(f"changes = {changes}")
                    else:
                        changes += len(temp)
                    log(f"changes = {changes}")

                temp = reverse(temp)
                customers = temp + customers
                del customers[0]
                log(f"customers = {customers}")
                break

    return changes

def main():
    customers = input().split()
    return changedPositions(customers)

print(main())