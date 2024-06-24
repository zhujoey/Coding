def log(s):

    print(s)
    pass

def letters(sentence):
    
    sentence = sentence.lower()
    lettercount = [sentence[0]]

    for i in range(1, len(sentence)):

        for j in range(len(lettercount)):

            if sentence[i] == lettercount[j]:

                break
            
            if j == len(lettercount) - 1:
                    
                lettercount.append(sentence[i])
    
    return len(lettercount)

def vowels(sentence):

    vowelcount = 0
    sentence = sentence.lower()

    for i in sentence:

        if i == "a" or i == "e" or i == "i" or i == "o" or i == "u":

            vowelcount += 1

    return vowelcount

def uppercase(sentence):

    uppercount = 0

    for i in sentence:

        if i.isupper() == True:

            uppercount += 1

    return uppercount

def mode(sentence):

    sentence = sentence.lower()    
    letterscount = {sentence[0] : 1}
    
    for i in range(1, len(sentence)):
        
        for j in (1, letterscount):
        
            if sentence[i] != j:
                
                letterscount.update({i : 1})
            
            else:
                
                j += 1
    
    return max(letterscount.values())

def main():

    sentence = input().strip().replace(" ", "").replace(",", "").replace(".", "")
    result = [str(letters(sentence)), str(vowels(sentence)), str(uppercase(sentence))]
    mode(sentence)

    return '''
'''.join(result)

print(main())