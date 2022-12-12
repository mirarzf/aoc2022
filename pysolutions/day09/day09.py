class Rope: 
    head = (0,0)
    tailpos = []

    def __init__(self) -> None:
        self.head = (0,0)
        self.tailpos = [(0,0)]

    def isAdjactentTo(self, i, j): 
        tail = self.tailpos[-1]
        if abs(i-tail[0]) > 1 or abs(j-tail[1]) > 1: 
            return False 
        return True 
    
    def moveHeadTo(self, direction:str): 
            
        # Calculate the next head position 
        if direction == "L": # Going left 
            i = self.head[0]
            j = self.head[1]-1
        
        elif direction == "R": # Going Right 
            i = self.head[0]
            j = self.head[1]+1
            
        elif direction == "U": # Going Up 
            i = self.head[0]-1
            j = self.head[1]
            
        elif direction == "D": # Going Down 
            i = self.head[0]+1
            j = self.head[1]
        
        else: # In case direction is an empty string 
            pass 
        
        # Update the tail position 
        # if it won't be adjacent to 
        # the future position of the head 
        if not self.isAdjactentTo(i, j): 
            self.tailpos.append(self.head)

        # Update the head position 
        self.head = (i, j)

def solve(inputfile:str, puzzlepart:int): 
    f = open(inputfile, 'r')
    lines = f.readlines() 
    score = 0 

    rope = Rope()
    for line in lines: 
        linesplit = line.split()
        direction = linesplit[0]
        numberOfSteps = int(linesplit[1])
        for ind in range(numberOfSteps): 
            rope.moveHeadTo(direction=direction)
    
    score = len(set(rope.tailpos))

    return score 