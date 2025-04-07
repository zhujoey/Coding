import math
import os
import random
import re
import sys
# Complete the 'findLastBinary' function below.
# The function is expected to return an INTEGER.
# The function accepts STRING s as parameter.

def log(s):
    #print(s)
    pass

def binary(num):
    return format(num, "#010b")[2:]

assert binary(5) == "00000101"

def is_in(str_long, str_short):
    return str_long.find(str_short) != -1

assert is_in("abc", "ab")
assert not is_in("abc", "d")

def findlastbinary(string):

    findinstring = 0
    binarynums = []
    for char in string:
        binarynums.append(binary(ord(char)))
    
    log(f"binarynums = {binarynums}")
    binarynums = "".join(binarynums)
    log(f"binarynums after join = {binarynums}")

    while is_in(binarynums, bin(findinstring)[2:]):
        
        findinstring += 1
        log(f"findinstring = {findinstring}")
        
    return findinstring - 1

def main():

    # Read the problem
    # Search it up
    # Make meaning in variable names
    # Know the difference between int and str
    # Don't run in visual studio
    # 刷牙
    # Don't add How to or preposition in search

    sentence = input()
    return findlastbinary(sentence)

print(main())