def log(s):
    print(s)
    pass

def findarea(boardpos, board2pos):

    left = int(boardpos[0])
    right = int(boardpos[2])
    up = int(boardpos[3])
    down = int(boardpos[1])
    boardleft = int(board2pos[0])
    boardright = int(board2pos[2])
    boardup = int(board2pos[3])
    boarddown = int(board2pos[1])
    coverarea = 1

    if boardleft < left:
        boardleftdimension = left
    else:
        coverarea = 0
    
    if boardright > right:
        boardrightdimension = right
    else:
        coverarea = 0

    if boarddown < down:
        boarddowndimension = down
    else:
        coverarea = 0
    
    if boardup > up:
        boardupdimension = up
    else:
        coverarea = 0

    if coverarea == 0:
        totalarea = (right - left) * (up - down)
    else:
        totalarea = (right - left) * (up - down) - (boardrightdimension - boardleftdimension) * (boardupdimension - boarddowndimension)

    return totalarea

def main():

    board1pos = input().split()
    board2pos = input().split()
    return findarea(board1pos, board2pos)

print(main())