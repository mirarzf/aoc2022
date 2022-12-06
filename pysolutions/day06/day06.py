def isAllDifferent(packet): 
    packetChar = {} 
    for c in packet: 
        if c in packetChar.keys(): 
            return False 
        else: 
            packetChar[c] = 1
    return True 

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
        if isAllDifferent(packet): 
            return i+lenmarker
    
    return n-1