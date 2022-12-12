def getNextMove(newheadpos, tailpos): 
    hi, hj = newheadpos
    ti, tj = tailpos
    newtailpos = 0, 0

    if abs(hi-ti) == 2 and abs(hj-tj) == 0: # Same column, different rows
        return ti+(hi-ti)//2, tj
    elif abs(hi-ti) == 0 and abs(hj-tj) == 2: # Same row, different columns 
        return ti, tj+(hj-tj)//2 
    elif abs(hi-ti) == 2 and abs(hj-tj) == 1: # Diagonal, adjacent columns 
        return ti+(hi-ti)//2, tj+(hj-tj)
    elif abs(hi-ti) == 1 and abs(hj-tj) == 2: # Diagonal, adjacent rows 
        return ti+(hi-ti), tj+(hj-tj)//2
    elif abs(hi-ti) == 2 and abs(hj-tj) == 2: # Diagonal, nothing adjacent 
        return ti+(hi-ti)//2, tj+(hj-tj)//2

    return newtailpos

class Rope: 
    knots = [(0,0) for i in range(10)]
    tailpos = []

    def __init__(self, nbOfRopes:int) -> None:
        self.knots = [(0,0) for i in range(nbOfRopes)]
        self.tailpos = [(0,0)]

    def isAdjactentTo(self, i, j, tail): 
        if abs(i-tail[0]) == 2 or abs(j-tail[1]) == 2: 
            return False 
        return True 
    
    def moveHeadTo(self, direction:str): 
        newpos = []
        head = self.knots[0]
        # Calculate the next head position 
        if direction == "L": # Going left 
            i = head[0]
            j = head[1]-1
        
        elif direction == "R": # Going Right 
            i = head[0]
            j = head[1]+1
            
        elif direction == "D": # Going Down 
            i = head[0]-1
            j = head[1]
            
        elif direction == "U": # Going Up 
            i = head[0]+1
            j = head[1]
        
        else: # In case string is empty 
            pass 

        newpos.append((i,j))  

        for k in range(1, len(self.knots)): 
            head = newpos[-1]
            i, j = head[0], head[1]
            
            # Update the knots position 
            # if it won't be adjacent to 
            # the future position of the head 
            if not self.isAdjactentTo(i, j, self.knots[k]): 
                newpostuple = getNextMove((i,j), self.knots[k])
                
                if k == len(self.knots)-1: 
                    # Update the tail position 
                    self.tailpos.append(newpostuple)
            
            else: 
                newpostuple = self.knots[k]

            # Add to the future positions list 
            newpos.append(newpostuple)
    
        # Update all positions 
        for k in range(len(self.knots)): 
            self.knots[k] = newpos[k]
        

def solve(inputfile:str, puzzlepart:int): 
    f = open(inputfile, 'r')
    lines = f.readlines() 
    score = 0 

    if puzzlepart == 1: 
        rope = Rope(2)
    else: # puzzlepart == 2 
        rope = Rope(10)
    for line in lines: 
        linesplit = line.split()
        direction = linesplit[0]
        numberOfSteps = int(linesplit[1])
        for ind in range(numberOfSteps): 
            rope.moveHeadTo(direction=direction)
    
    score = len(set(rope.tailpos))

    return score 