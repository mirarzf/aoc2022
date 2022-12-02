import sys
sys.path.append('pysolutions')
import argparse
from pathlib import Path

from pysolutions import Dailypuzzle

inputfolder = Path('./input')

def get_args():
    parser = argparse.ArgumentParser(description='Choose the day problem and input')
    parser.add_argument('day', metavar='DAY', type=int, help='Day number of the problem to solve.')
    parser.add_argument('--part', '-p', metavar='PART', type=int, choices=[1, 2], help='Part of the problem to solve. ' 
                        'Will give solution to both parts if not specified.')
    parser.add_argument('--input', '-i', metavar='INPUT', type=str, help='Input filename. Must be txt.')

    return parser.parse_args()

if __name__ == '__main__': 
    args = get_args()
    if args.input == None: 
        inputfile = Path(inputfolder / f'day{args.day:02d}.txt')
    else: 
        inputfile = args.input 
    print(f'The input file path is "{inputfile.name}" and is located in directory "{inputfile.parent}". ')
    
    puzzle = Dailypuzzle(args.day, inputfile)

    if args.part == None: 
        print(f'The solution to problem of day {args.day} part 1 is {puzzle.solve(1)}. ')
        print(f'The solution to problem of day {args.day} part 2 is {puzzle.solve(2)}. ')
    else: 
        print(f'The solution to problem of day {args.day} part {args.part} is {puzzle.solve(args.part)}. ')
