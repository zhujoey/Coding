def log(s):
    print(s)
    pass

def findarea(boardpos, truckpos):

    left = int(boardpos[0])
    right = int(boardpos[2])
    up = int(boardpos[3])
    down = int(boardpos[1])
    truckleft = int(truckpos[0])
    truckright = int(truckpos[2])
    truckup = int(truckpos[3])
    truckdown = int(truckpos[1])
    truckcoverarea = 1

    if truckleft > left and truckleft < right:
        truckleftdimension = truckleft
    elif truckleft < left:
        truckleftdimension = left
    else:
        truckcoverarea = 0
    
    if truckright > left and truckright < right:
        truckrightdimension = truckright
    elif truckright > right:
        truckrightdimension = right
    else:
        truckcoverarea = 0
        
    if truckdown > down and truckdown < up:
        truckdowndimension = truckdown
    elif truckdown < down:
        truckdowndimension = down
    else:
        truckcoverarea = 0
    
    if truckup > down and truckup < up:
        truckupdimension = truckup
    elif truckup > up:
        truckupdimension = up
    else:
        truckcoverarea = 0

    if truckcoverarea == 0:
        totalarea = (right - left) * (up - down)
    else:
        totalarea = (right - left) * (up - down) - (truckrightdimension - truckleftdimension) * (truckupdimension - truckdowndimension)

    return totalarea

   
def main():
    board1pos = input().split()
    board2pos = input().split()
    truckpos = input().split()
    return findarea(board1pos, truckpos) + findarea(board2pos, truckpos)

print(main())