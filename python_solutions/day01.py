def solve(inputfile, puzzlepart): 
    f = open(inputfile, 'r')
    lines = f.readlines()

    topcal = [0,0,0] 
    calsum = 0 
    for line in lines: 
        if line == '\n': 
            if topcal[0] < calsum: 
                topcal[0] = calsum
                topcal.sort()
            calsum = 0
        else: 
            calsum += int(line)
    
    if puzzlepart == 1: 
        return topcal[2]
    else: 
        return sum(topcal)