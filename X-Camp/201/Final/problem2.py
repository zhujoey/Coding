def log(s):
    print(s)
    pass

def dfs(x, y, status, size, iteration):
    if status[f"{x}, {y}"] == "Mountains" or status[f"{x}, {y}"] == "Beach":
        return iteration
    elif status[f"{x}, {y}"] == "X":
        return
    elif status[f"{x}, {y}"] == ".":
        iteration += 1
        if y > 0:
            dfs(x, y - 1, status, size, iteration)
        if y < size - 1:
            dfs(x, y + 1, status, size, iteration)
        if x > 0:
            dfs(x - 1, y, status, size, iteration)
        if x < size - 1:
            dfs(x + 1, y, status, size, iteration)

def main():
    size = int(input())
    status = {}
    for y in range(size):
        templist = input().strip().replace(" ", "")
        for x in range(len(templist)):

            if templist[x]== ".":
                status.update({f"{x}, {y}" : "Path"})
            elif templist[x] == "X":
                status.update({f"{x}, {y}" : "Block"})
            elif templist[x] == "M":
                status.update({f"{x}, {y}" : "Mountains"})
            elif templist[x] == "B":
                status.update({f"{x}, {y}" : "Beach"})
            elif templist[x] == "@":
                status.update({f"{x}, {y}" : "Start"})
                startx = x
                starty = y
    return dfs(startx, starty, status, size, 0)

print(main())