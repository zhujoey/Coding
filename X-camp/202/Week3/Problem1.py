def log(s):
    print(s)
    pass

def findmax(antivirusamount, toxicity):
    eradicatenum = []

    for i in range(len(toxicity)):
        j = i
        temp = antivirusamount

        while j < len(toxicity):
            if temp - int(toxicity[j]) >= 0:
                temp = temp - int(toxicity[j])
            else:
                break
            j += 1
        eradicatenum.append(j - i)

    return max(eradicatenum)

def main():
    antivirusamount = int(input().split()[1])
    toxicity = input().split()

    return findmax(antivirusamount, toxicity)

print(main())