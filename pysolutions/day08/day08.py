def getVisionFromSide(treeGrid, side:str, row:int): 
    if side == "left" or side == "right":  
        treeRow = treeGrid[row]
        nline = len(treeRow)
    else: # side == "up" or side == "down"
        treeRow = [treeline[row] for treeline in treeGrid]
        nline = len(treeRow)
    
    visionFromSide = [True for i in range(nline)]

    if side == "left" or side == "up": 
        previousTree = treeRow[0]
        currTree = 0 
        for i in range(1, nline-1):
            currTree = treeRow[i]
            if previousTree >= currTree: 
                visionFromSide[i] = False 
            else: 
                previousTree = currTree
    
    if side == "right" or side == "down": 
        previousTree = treeRow[-1]
        currTree = 0 
        for i in range(nline-2, -1, -1):
            currTree = treeRow[i]
            if previousTree >= currTree: 
                visionFromSide[i] = False 
            else: 
                previousTree = currTree
    
    return visionFromSide

def distToNextVisible(treeGrid, side:str, i:int, j:int): 
    maxi = treeGrid[i][j]

    if side == "left": 
        for k in range(j-1, -1, -1): 
            if treeGrid[i][k] >= maxi: 
                return j-k 
        return j
    
    elif side == "right": 
        for k in range(j+1, len(treeGrid[0])): 
            if treeGrid[i][k] >= maxi: 
                return k-j
        return len(treeGrid[0])-j-1

    elif side == "up": 
        for k in range(i-1, -1, -1): 
            if treeGrid[k][j] >= maxi: 
                return i-k
        return i
    
    else: # side == "down"
        for k in range(i+1, len(treeGrid)): 
            if treeGrid[k][j] >= maxi: 
                return k-i
        return len(treeGrid)-i-1
        


def getHVvision(treeGrid, side:str, row:int): 
    if side == "horizontal": 
        visionFromLeft = getVisionFromSide(treeGrid, "left", row)
        visionFromRight = getVisionFromSide(treeGrid, "right", row)
        HVvision = [visionFromRight[i] or visionFromLeft[i] for i in range(len(treeGrid[0]))]
        
    else: # side == "vertical": 
        visionFromUp = getVisionFromSide(treeGrid, "up", row)
        visionFromDown = getVisionFromSide(treeGrid, "down", row)
        HVvision = [visionFromUp[i] or visionFromDown[i] for i in range(len(treeGrid))]

    return HVvision

def solve(inputfile:str, puzzlepart:int): 
    f = open(inputfile, 'r')
    lines = f.readlines() 
    score = 0 

    grid = []
    visGrid = []

    for i, line in enumerate(lines): 
        treeRow = []
        for e in line: 
            if e != "\n": 
                treeRow.append(int(e))
        grid.append(treeRow)
        visionHorizontal = getHVvision(treeGrid=grid, side="horizontal", row=i)
        visGrid.append(visionHorizontal)

    if puzzlepart == 1:  
        for j in range(len(visGrid[0])): 
            visionVertical = getHVvision(treeGrid=grid, side="vertical", row=j)
            for i in range(len(visGrid)): 
                if visGrid[i][j] or visionVertical[i]: 
                    score += 1            
    
    if puzzlepart == 2: 
        nrow = len(grid)
        ncol = len(grid[0])
        for i in range(nrow):
            for j in range(ncol): 
                scenicScore = distToNextVisible(grid, "left", i, j)
                scenicScore *= distToNextVisible(grid, "right", i, j)
                scenicScore *= distToNextVisible(grid, "up", i, j)
                scenicScore *= distToNextVisible(grid, "down", i, j)
                if scenicScore > score: 
                    score = scenicScore          

    return score 