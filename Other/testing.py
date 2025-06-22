import random
def makeSong(parts, repeats):
    song = ""
    for i in range(repeats):
        song += random.choice(parts) + "\n"
    return song

print(makeSong(["a", "sdfadf", "eawef"], 4))