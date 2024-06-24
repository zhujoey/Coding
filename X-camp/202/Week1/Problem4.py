def log(s):
    print(s)
    pass

def findcircles(friends):
    pass

def main():
    friends = []
    size = int(input())
    for i in range(size):
        friends.append(input().split(" "))

    return findcircles(friends)

print(main)