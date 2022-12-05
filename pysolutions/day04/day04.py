def getPair(line:str): 
    pair = [[int(e) for e in element.split('-')] for element in line.split(',')]
    return pair 

def completeOverlap(pair:list): 
    if pair[0][0] == pair[1][0]: 
        return True 
    elif pair[0][0] < pair[1][0]: 
        return pair[0][1] >= pair[1][1]
    else: # pair[0][0] > pair[1][0]
        return pair[0][1] <= pair[1][1]

def overlap(pair:list): 
    if pair[0][0] == pair[1][0]: 
        return True 
    elif pair[0][0] < pair[1][0]: 
        return pair[0][1] >= pair[1][0]
    else: # pair[0][0] > pair[1][0]
        return pair[1][1] >= pair[0][0]

def solve(inputfile:str, puzzlepart:int): 
    f = open(inputfile, 'r')
    lines = f.readlines()

    score = 0 
    for line in lines: 
        pair = getPair(line)
        if puzzlepart == 1 and completeOverlap(pair):  
            score += 1 
        if puzzlepart == 2 and overlap(pair): 
            score += 1 
    return score