#!/bin/python3

import math
import os
import random
import re
import sys




# Complete the 'findDigitSum' function below.

# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER num
#  2. INTEGER base
#  3. INTEGER start

number = int(input())
basenum = int(input())
startnum = int(input())


def findDigitSum(num, base, start):
    
    basetennums = []
    numstoadd = 0
    finalnums = []
    finalsum = 0
        
    for i in range(1, len(str(start)) + 1):
        
        numstoadd += int(str(start)[-i]) * base ** (i - 1)
        
    basetennums.append(numstoadd)

    for i in range(num - 1):
        
        numstoadd += 1
        basetennums.append(numstoadd)

    for i in basetennums:
        
        remainder = []
        
        while i > 0:

            remainder.append(str(i % base))
            i = i // base
        
        remainder.reverse()
        finalnums.append("".join(remainder))
    
    for i in range(len(finalnums)):
        
        finalnums[i] = list(finalnums[i])
        
        for j in range(len(finalnums[i])):
            
            finalsum += int(finalnums[i][j])
    
    return finalsum

print(findDigitSum(number, basenum, startnum))