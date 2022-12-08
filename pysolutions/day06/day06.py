def solve(inputfile:str, puzzlepart:int): 
    f = open(inputfile, 'r')
    lines = f.readlines() 
    line = lines[0]
    n = len(line)

    if puzzlepart == 1: 
        lenmarker = 4 
    else: # puzzlepart == 2 
        lenmarker = 14 
    
    for i in range(0, n-lenmarker): 
        packet = line[i:i+lenmarker]
        if len(set(packet)) == lenmarker: 
            return i+lenmarker
    
    return n-1