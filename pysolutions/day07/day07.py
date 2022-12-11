def solve(inputfile:str, puzzlepart:int): 
    f = open(inputfile, 'r')
    lines = f.readlines() 
    score = 0 
    
    dirSizes = {"/": 0}
    currPath = ["/"]

    for line in lines:  
        linesplit = line.split() 
        if linesplit[0] == '$' and linesplit[1] == "cd": 
            # Change directory 
            if linesplit[2] != "..": 
                # Explore subdirectory 
                currPath.append(linesplit[2])
                # print("on descend", currPath[-1])
            else: 
                # Explore parent directory 
                currPath.pop()
                # print("on remonte", currPath[-1])

        elif line[0] != '$': # ls output    
            if linesplit[0] == "dir": 
                # Add subdir to list of directories 
                dirSizes[linesplit[1]] = 0
                # print("yo", linesplit[1], currPath[-1])
                
            else:  
                # Add file to current directory 
                # ie update size of all directories in the path of the file 
                for dir in currPath: 
                    dirSizes[dir] += int(linesplit[0])
                    # print(dir, dirSizes[dir])

    if puzzlepart == 1: 
        for dir in dirSizes.keys(): 
            size = dirSizes[dir]
            if size <= 100000: 
                print(dir, size)
                score += size
        
    return score 