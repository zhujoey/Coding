'''
class Fraction:
    
    def __init__(self, top, bottom):
        common = gcd(top, bottom)
        self.num = top // common
        self.den = bottom // common
    
    def show(self):
        print(self.num, "/", self.den)
    
    def __str__(self):
        return str(self.num) + "/" + str(self.den)
    
    def __add__(self, other_fraction):
        new_num = self.num * other_fraction.den + self.den * other_fraction.num
        new_den = self.den * other_fraction.den
        return Fraction(new_num, new_den)
    
    def __sub__(self, other_fraction):
        new_num = self.num * other_fraction.den - self.den * other_fraction.num
        new_den = self.den * other_fraction.den
        return Fraction(new_num, new_den)
    
    def __sub__(self, other):
        return self + Fraction(-other.num, other.den)
    
    def __mul__(self, other_fraction):
        new_num = self.num * other_fraction.num
        new_den = self.den * other_fraction.den
        return Fraction(new_num, new_den)
    
    def __truediv__(self, other_fraction):
        new_num = self.num * other_fraction.den
        new_den = self.den * other_fraction.num
        return Fraction(new_num, new_den)
    
    def __truediv__(self, other):
        return self * Fraction(other.den, other.num)
    
    def __eq__(self, other):
        first_num = self.num * other.den
        second_num = other.num * self.den
        return first_num == second_num
    
    def __ne__(self, other):
        first_num = self.num * other.den
        second_num = self.den * other.num
        return first_num != second_num

    def __ne__(self, other):
        return not (self == other)
    
    def get_num(self):
        return self.num
    
    def get_den(self):
        return self.den
    
def gcd(m, n):
    while m % n != 0:
        old_m = m
        old_n = n
        
        m = old_n
        n = old_m % old_n
        
    return n

import time
          
def sum_of_n(n):
    
    start = time.time()
    
    the_sum = 0
    
    for i in range(1, n + 1):
        the_sum = the_sum + i
        
    end = time.time()
        
    return the_sum, end - start

def sum_of_n_3(n):
    
    return (n * (n + 1)) / 2

start = time.time()

print(sum_of_n_3(99999999))

end = time.time()

print(end - start)
print(sum_of_n(99999999))

a = [3, 54, 4, 244, 23, 5, 45, 2, 5, 1, -4, 65, -10]

def find_min(a):
    
    min = a[0]
    
    for i in range(1, len(a)):
        
        if a[i] < min:
            
            min = a[i]
        
    return min

print(find_min(a))      


def find_anagram(s1, s2):
    
    l1 = [0] * 26
    l2 = [0] * 26
    
    for i in range(len(s1)):
        
        pos = ord(s1[i]) - ord("a")
        l1[pos] += 1
        
    for i in range(len(s2)):
        
        pos = ord(s2[i]) - ord("a")
        l2[pos] += 1
        
    j = 0
    still_ok = True
    
    while j < 26 and still_ok:
        
        if l1[j] == l2[j]:
            j += 1
        
        else:
            still_ok = False
    
    return still_ok

print(find_anagram("idontevenhaveapythonfile", "elifnohtypaevahnevetnodi"))



def is_parenthesis_balanced(items):
    
    class Stack:
        def __init__(self):
            self.items = []
        
        def is_empty(self):
            return len(self.items) == 0
        
        def push(self, item):
            self.items.append(item)
        
        def pop(self):
            return self.items.pop()
        
        def peek(self):
            return self.items[len(self.items) - 1]
        
        def size(self):
            return len(self.items)
        
        def print(self):
            for i in range(0, len(self.items)):
                print(self.items[i]
                )
                
    x = 0
    stack = Stack()

    while x <= len(items) - 1:
        print(items[x])
        
        if items[x] == "(":
            stack.push("(")
            x += 1
            
        elif items[x] == "[":
            stack.push("[")
            x += 1
            
        elif items[x] == "{":
            stack.push("{")
            x += 1
            
        elif items[x] == ")" and not stack.is_empty() and x <= len(items) and stack.peek() == "(":
            stack.pop()
            x += 1
        
        elif items[x] == "]" and not stack.is_empty() and x <= len(items) and stack.peek() == "[":
            stack.pop()
            x += 1
    
        elif items[x] == "}" and not stack.is_empty() and x <= len(items) and stack.peek() == "{":
            stack.pop()
            x += 1
        
        elif stack.is_empty():
            return False
            
    if stack.is_empty():
        return True

    else:
        return False
    
a = ["[", "{", "}", "]", ")"]    

print(is_parenthesis_balanced(a))


import random





def samebirthday(amountofpeople):
    
    x = 0
    y = 1
    a = []
    
    for i in range(amountofpeople):
        
        x = random.randint(1, 365)
        a.append(x)
        
    a.sort()
    
    while y <= len(a) - 1:
        
        if a[y] == a[y - 1]:
             
            return True
        
        y += 1
    
    return False

def repeat(numberoftimes):
    
    truecount = 0
    falsecount = 0
    
    for i in range(numberoftimes):
        
        if samebirthday(84) == True:
            truecount += 1
            
        else:
            falsecount += 1
    
    print("truecount =", truecount, ", falsecount =", falsecount)
    if truecount > falsecount:
        print("more people have same birthdays")
    
    elif falsecount > truecount:
        print("more people have different birthdays")
        
    else:
        print("unknown")
        
    
        
repeat(1000)
'''

class Stack:
        def __init__(self):
            self.items = []
        
        def is_empty(self):
            return len(self.items) == 0
        
        def push(self, item):
            self.items.append(item)
        
        def pop(self):
            return self.items.pop()
        
        def peek(self):
            return self.items[len(self.items) - 1]
        
        def size(self):
            return len(self.items)
        
        def print(self):
            for i in range(0, len(self.items)):
                print(self.items[i]
                )
                
def divide_by_8(dec_number):
    rem_stack = Stack()
    
    while dec_number > 0:
        rem = dec_number % 8
        rem_stack.push(rem)
        dec_number = dec_number // 8
        
    octal_string = ""
    while not rem_stack.is_empty():
        octal_string = octal_string + str(rem_stack.pop())
        
    return octal_string

print(divide_by_8(8))

import math
