def getValueAssociatedToMove(letter): 
    if letter == "A" or letter == "X": # Rock 
        return 1 
    elif letter == "B" or letter == "Y": # Paper 
        return 2
    elif letter == "C" or letter == "Z": # Scissors 
        return 3 
    else: 
        return 0

def getRoundResult(opponent, yourself): 
    opp = getValueAssociatedToMove(opponent)
    yself = getValueAssociatedToMove(yourself)

    if opp == 0 or yself == 0: 
        return 0
    elif opp-yself == 0: # Draw 
        return yself + 3 
    elif (yself-opp) % 3 == 1: # Win 
        return yself + 6 
    else: # Loss 
        return yself 

def getRoundResult2(opponent, result): 
    opp = getValueAssociatedToMove(opponent)
    res = getValueAssociatedToResult(result)

    if opp == 0: 
        return 0 
    elif res == 3: # Draw 
        return opp + 3
    elif res == 6: # Win 
        return (opp % 3) + 7; 
    else: # Loss  
        if opp == 1: 
            return 3 
        else: 
            return opp-1

def getValueAssociatedToResult(letter): 
    if letter == "X": # Loss 
        return 0
    elif letter == "Y": # Draw 
        return 3
    elif letter == "Z": # Win 
        return 6 
    else: 
        return 0 

def solve(inputfile, puzzlepart): 
    f = open(inputfile, 'r')
    lines = f.readlines()

    score = 0 
    for line in lines: 
        opponent = line[0] 
        second = line[2]

        if puzzlepart == 1: 
            score += getRoundResult(opponent, second)
        else: 
            score += getRoundResult2(opponent, second)

    return score