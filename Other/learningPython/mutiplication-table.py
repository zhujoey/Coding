def table_of_products():
    for i in range(1, 10):
        for n in range(i, 10):
            print('%s * %s = %2d ' % (i, n, i * n), end='')
        print('')
table_of_products()
