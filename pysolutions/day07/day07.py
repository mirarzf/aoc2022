def pathListToString(pathlist:list): 
    pathstring = ""
    for dir in pathlist: 
        pathstring += dir 
        pathstring += "/"
    return pathstring

def solve(inputfile:str, puzzlepart:int): 
    f = open(inputfile, 'r')
    lines = f.readlines() 
    score = 0 
    
    dirSizes = {pathListToString(["/"]): 0}
    currPath = []

    for line in lines:  
        linesplit = line.split() 
        if linesplit[0] == '$' and linesplit[1] == "cd": 
            # Change directory 
            if linesplit[2] != "..": 
                # Explore subdirectory 
                currPath.append(linesplit[2])
            else: 
                # Explore parent directory 
                currPath.pop()

        elif line[0] != '$': # ls output    
            if linesplit[0] == "dir": 
                # Add subdir to list of directories 
                subdirpath = pathListToString(currPath + [linesplit[1]])
                dirSizes[subdirpath] = 0
                
            else:  
                # Add file to current directory 
                # ie update size of all directories in the path of the file 
                for i in range(len(currPath)): 
                    dirkey = pathListToString(currPath[:i+1])
                    dirSizes[dirkey] += int(linesplit[0])
        
    if puzzlepart == 1: 
        for dir in dirSizes.keys(): 
            size = dirSizes[dir]
            if size <= 100000: 
                score += size
    
    if puzzlepart == 2: 
        outerSize = dirSizes["//"]
        minimumSpace = outerSize - 40000000
        minimalDirSpace = outerSize
        for dir in dirSizes.keys(): 
            if dirSizes[dir] < minimalDirSpace and dirSizes[dir] > minimumSpace:  
                minimalDirSpace = dirSizes[dir]
        return minimalDirSpace
    return score 