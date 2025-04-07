from asyncore import write


def cowpoints(measurements):
    points = [7, 7, 7]
    times = 0
    for i in range(len(measurements))                                                                                                                                           :
        tempmax = max(points)
        beforemaxindex = []
        aftermaxindex = []

        for j in range(3):
            if points[j] == tempmax:
                beforemaxindex.append(j)

        if measurements[i][1] == "Bessie":
            points[0] = points[0] + measurements[i][2]
        elif measurements[i][1] == "Elsie":
            points[1] = points[1] + measurements[i][2]
        elif measurements[i][1] == "Mildred":
            points[2] = points[2] + measurements[i][2]

        tempmax = max(points)

        for k in range(3):
            if points[k] == tempmax:
                aftermaxindex.append(k)

        if beforemaxindex != aftermaxindex:
            times += 1

    return times

def main():
    nummeasures = int(input())
    measurements = []

    for i in range(nummeasures):
        temp = input().split()
        temp[0] = int(temp[0])
        temp[2] = int(temp[2])
        measurements.append(temp)
        
    measurements = sorted(measurements)

    return cowpoints(measurements)

print(main())