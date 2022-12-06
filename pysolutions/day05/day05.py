def isACapitalLetter(c:str): 
    if ord(c) >= 65 and ord(c) <= 90: 
        return True 
    else: 
        return False

def invert(list): 
    return [list[i] for i in range(len(list)-1, -1, -1)]

def getPilesAndInstructions(inputfile): 
    f = open(inputfile, 'r')
    lines = f.readlines()

    n = len(lines[0]) 
    nbOfStacks = (n-3)//4 + 1 
    temp = [[] for i in range(nbOfStacks)]
    instructions = []

    for line in lines: 
        if line[0] != 'm' and line != '\n': 
            for i in range(nbOfStacks): 
                j = i*4+1
                if (isACapitalLetter(line[j])): 
                    temp[i].append(line[j])

        if line[0] == 'm': 
            linelist = line.split(' ')
            instruction = [int(linelist[i])-1 for i in range(1, 6, 2)]
            instruction[0] += 1
            instructions.append(instruction)
    
    piles = []
    for i in range(nbOfStacks): 
        piles.append(invert(temp[i]))
    
    return piles, instructions

def getOut(stack, length): 
    movingOut = [] 
    for i in range(length): 
        movingOut.append(stack.pop())
    return movingOut

def move(instruction:list, piles:list, puzzlepart:int): 
    nbToMove, fromStack, toStack = instruction[0], piles[instruction[1]], piles[instruction[2]]
    moving = getOut(fromStack, nbToMove)
    if puzzlepart == 1: 
        toStack += moving
    else: # puzzlepart == 2 
        toStack += invert(moving)
    
    return piles

def solve(inputfile:str, puzzlepart:int): 
    piles, instructions = getPilesAndInstructions(inputfile=inputfile)
    for instruct in instructions: 
        piles = move(instruction=instruct, piles = piles, puzzlepart=puzzlepart)    
    lastOfStacksList = [stack[-1] for stack in piles]
    lastOfStacks = ""
    for e in lastOfStacksList: 
        lastOfStacks += e 
    return lastOfStacks