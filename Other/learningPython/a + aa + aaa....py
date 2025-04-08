#(The number of time you add, The number you use to add)
#Result: the sum of all the numbers.
def n_and_n(times, num):
    result = 0
    first = num
    for i in range(times):
        result = result + num
        print(num)
        num = num * 10 + first
    print(result)
n_and_n(3, 3)
