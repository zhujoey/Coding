def log(s):
    print(s)
    pass

def findsquares(x, y, maze, height, width, visited):

    if maze[y][x] == "to be visited":
        maze[str(x) + ", " + str(y)] = "visited"
        visited.append((x, y))

        if x > 0 and y > 0:
            findsquares(x - 1, y - 1, maze, height, width, visited)

        if x < width - 1 and y < height - 1:
            findsquares(x + 1, y + 1, maze, height, width, visited)
        
        if x < width - 1 and y > 0:
            findsquares(x + 1, y - 1, maze, height, width, visited)
        
        if x > 0 and y < height - 1:
            findsquares(x - 1, y + 1, maze, height, width, visited)

        if y > 0:
            findsquares(x, y - 1, maze, height, width, visited)

        if y < height - 1:
            findsquares(x, y + 1, maze, height, width, visited)
        
        if x > 0:
            findsquares(x - 1, y, maze, height, width, visited)
        
        if x < width - 1:
            findsquares(x + 1, y, maze, height, width, visited)
    return visited

def countzones(height, width, maze):
    visited = []
    for y in range(height):
        for x in range(width):
            if maze[y][x] == "W":
                findsquares(x, y, maze, height, width, visited)

def main():
    temp = input()
    temp = temp.split()
    height = int(temp[0])
    width = int(temp[1])
    maze = []

    for i in range(height):
        maze.append(input().split())

    return countzones(height, width, maze)
    

print(main())