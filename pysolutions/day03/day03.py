def getDoubledLetter(rucksack:str): 
    n = len(rucksack)
    contentMap = {} 
    for i in range(n//2): 
        if contentMap.get(rucksack[i]) == None: 
            contentMap[rucksack[i]] = 1
    
    for i in range(n//2, n): 
        if contentMap.get(rucksack[i]) != None: 
            return rucksack[i]
    return ' '

def getPriority(letter:str): 
    asciicode = ord(letter)
    if asciicode >= 97 and asciicode <= 122: # a to z
        return asciicode - 96
    elif asciicode >= 65 and asciicode <= 90: # A to Z
        return asciicode-38
    else: 
        return 0

def getBadge(groupOfRucksacks): 
    contentMap = {} 
    for nb in range(3): 
        rucksack = groupOfRucksacks[nb]
        for i in range(len(rucksack)): 
            key = rucksack[i]
            if contentMap.get(key) == None: 
                contentMap[key] = [nb]
            elif contentMap[key][-1] == nb-1: 
                contentMap[key].append(nb)
                if len(contentMap[key]) == 3: 
                    return key 
    return 0

def solve(inputfile:str, puzzlepart:int): 
    f = open(inputfile, 'r')
    lines = f.readlines()

    score = 0 
    groupOfRucksacks = []
    for i, line in enumerate(lines): 
        rucksack = line[:-1]
        if puzzlepart == 1: 
            double = getDoubledLetter(rucksack)
            score += getPriority(double)
        if puzzlepart == 2: 
            groupOfRucksacks.append(rucksack)
            if i % 3 == 2: 
                badge = getBadge(groupOfRucksacks)
                score += getPriority(badge)
                groupOfRucksacks = []
    return score