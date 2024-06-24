def log(s):
    print(s)
    pass

def circle(size):
    matrix = []
    for y in range(size):
        temp = []
        for x in range(size):
            temp.append(1)
        matrix.append(temp)

    for i in range(int(size / 2 + 0.5) - 1):
        for j in range(len(matrix)):
            for k in range(len(matrix[j])):
                if j > i and k > i and j < size - i - 1 and k < size - i - 1:
                    matrix[j][k] += 1
    
    for i in range(len(matrix)):
        for j in range(len(matrix[i])):
            matrix[i][j] = str(matrix[i][j])

    return matrix

def main():
    size = int(input())
    matrix = circle(size)
    temp = []
    for i in range(len(matrix)):
        temp.append(" ".join(matrix[i]))

    return '''
'''.join(temp)

print(main())