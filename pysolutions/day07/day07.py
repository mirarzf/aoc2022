def solve(inputfile:str, puzzlepart:int): 
    f = open(inputfile, 'r')
    lines = f.readlines() 
    score = 0 
    
    currDir = "/"
    parentsDir = {"/": ["", 0]}

    for line in lines:  
        linesplit = line.split() 
        if linesplit[0] == '$' and linesplit[1] == "cd": 
            # Change directory 
            if linesplit[2] != "..": 
                # Explore subdirectory 
                currDir = linesplit[2]
                print("on descend", currDir)
            else: 
                # Explore parent directory 
                currDir = parentsDir[currDir][0]
                print("on remonte", currDir)

        elif line[0] != '$': # ls output    
            if linesplit[0] == "dir": 
                # Add subdir to list of directories 
                parentsDir[linesplit[1]] = [currDir, 0]
                print("yo", linesplit[1], currDir)
                
            else:  
                # Add file to current directory 
                # ie update size of all directories in the path of the file 
                tempDir = str(list(currDir))
                print(type(tempDir))
                while tempDir != "": 
                    parentsDir[tempDir][1] += int(linesplit[0])
                    print("yay", tempDir, parentsDir[tempDir])
                    tempDir = parentsDir[tempDir][0]
                    if tempDir != "": 
                        print("yay2", tempDir, parentsDir[tempDir])

    if puzzlepart == 1: 
        for dir in parentsDir.keys(): 
            size = parentsDir[dir][1]
            if size <= 100000: 
                print(dir, size)
                score += size
        
    return score 