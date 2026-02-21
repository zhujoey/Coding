import queue

def log(s):
    print(s)
    pass

def bfs(size, maze, x, y):
    visited = {(0, 0)}
    visiting = queue.Queue()
    if x != 0 or y != 0:
        visited.add((x, y))
        
    visiting.put((x, y))

    if x > 0:
        visited.add((x - 1, y))
    if y > 0:
        visited.add((x, y - 1))
    if x < size - 1:
        visited.add((x + 1, y))
    if y < size - 1:
        visited.add((x, y + 1))

    visiting.get()

def main():
    size = int(input)
    maze = []
    for i in range(size):
        maze.append(input().split())

    return None

print(main())