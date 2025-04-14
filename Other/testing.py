import random

targetNum = random.randint(1, 100)
print("number guessing game")
guess = input("guess my number: ")

while guess != "stop":

    if (int(guess) == targetNum):
        print("good job! I came up with a new number")
        targetNum = random.randint(1, 100)

    elif int(guess) < targetNum:
        print("your number is too small")

    else:
        print("your number is too big")

    guess = input("Please guess: ")

print("game stopped")