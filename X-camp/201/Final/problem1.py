def log(s):
    print(s)
    pass

ans = 0
def dfs(x, y, maze, status, size):
    global ans
    if maze[y][x] == "-" or status[y][x] == True:
        return

    elif maze[y][x] == "*" or maze[y][x] == "_":
        ans += 1
        maze[y][x] = True

        if y > 0:
            dfs(x, y - 1, maze, status, size)
        if y < size - 1:
            dfs(x, y + 1, maze, status, size)
        if x > 0:
            dfs(x - 1, y, maze, status, size)
        if x < size - 1:
            dfs(x + 1, y, maze, status, size)

def main():
    size = int(input())
    maze = []
    status = []

    for y in range(size):
        templist = []
        for x in range(size):
            templist.append(False)
        status.append(templist)

    for y in range(size):
        templist = list(input().strip())
        for x in range(len(templist)):
            if templist[x] == "*":
                faucetx = x
                faucety = y 
        maze.append(templist)

    dfs(faucetx, faucety, maze, status, size)
    return ans

print(main())