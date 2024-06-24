'''
#1
def count1(s):

    res = 0
    values = {'0' : 0, '1' : 1, '2' : 1, '3' : 2, '4' : 1, '5' : 2, '6' : 2, '7' : 3}

    for char in s:
        if char in values:
            res = res + values[char]

    return res

#print(count1("1"))

#2


#print(hextooctal("3F6A"))

#3
def rhombus(n):

    n = (n - 1) * 8 + 4
    return n

#print(rhombus(6))


#4
def f(n):

    if n >= 10:
        return f(n - 2) - 3

    elif 3 <= n < 10:
        return f(2 * n - 10) + 4

    else:
        return n * n + 5

#print(f(12))


def Acsl99(s):

    ints = s.split(",")
    points = int(ints[0])
    cards = [ints[1], ints[2], ints[3]]
    worth = 0
    x = 4
    n = 0

    while x < len(ints):

        if x % 2 == 0:
            n = int(cards[0])
        if x % 2 == 1:
            n = int(ints[x])           
        if n == 9:
            worth = 0

        elif n == 4:
            worth = -10

        elif n == 0:

            if points + 11 <= 99:
                worth = 11
            else:
                worth = 1
        else:
            worth = n

        points += worth

        if x % 2 == 0:
            del cards[0]
            cards.append(ints[x])

        if points >= 99:
            if x % 2 == 0:
                return points, "dealer"
            elif x % 2 == 1:
                return points, "player"
        x += 1

print(Acsl99("87,5,8,9,7,4,6,3,9,0,2"))
print(Acsl99("78,2,4,8,3,8,5,0,6,9,8"))
print(Acsl99("85,7,9,7,6,5,9,4,5,0,1"))
print(Acsl99("84,8,4,2,7,9,0,1,9,8,3"))
print(Acsl99("95,9,0,9,0,1,0,1,0,2,5"))
print(Acsl99("65,0,8,0,7,0,6,0,5,1,4"))
print(Acsl99("74,2,0,1,8,2,0,1,7,0,4"))
print(Acsl99("84,2,4,6,8,0,3,9,1,5,7"))
print(Acsl99("92,0,1,2,3,4,5,6,7,8,9"))
print(Acsl99("80,9,7,5,3,1,8,6,4,2,0"))
'''

input = input()

def cardgame(sample):
    sample = sample.split(",")
    points = int(sample[0])
    playercards = [sample[1], sample[2], sample[3]]

    for i in range(4, 11):

        if points > 99:
            if i % 2 == 0:
                return points, "player"
            elif i % 2 == 1:
                return points, "dealer"

        if i % 2 == 0:
            if playercards[0] == 9:
                pass
            elif playercards[0] == 4:
                points += -10
            elif playercards[0] == 0:
                if points + 11 > 99:
                    points += 1
                else:
                    points += 11
            else:
                points += int(playercards[0])
                
            del playercards[0]
            playercards.append(sample[i])
            
        elif i % 2 == 1:
            if sample[i] == 9:
                pass
            elif sample[i] == 4:
                points += -10
            elif sample[i] == 0:
                if points + 11 > 99:
                    points += 1
                else:
                    points += 11
            else:
                points += int(sample[i])

print(cardgame(input))