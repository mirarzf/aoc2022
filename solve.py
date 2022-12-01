import argparse
from pathlib import Path

from python_solutions import *
import python_solutions as ps

inputfolder = Path('./input')

function_mapping = { 
    'day01': ps.day01.solve, 
    # 'day02': python_solutions.day02, 
    # 'day03': python_solutions.day03, 
    # 'day04': python_solutions.day04, 
    # 'day05': python_solutions.day05, 
    # 'day06': python_solutions.day06, 
    # 'day07': python_solutions.day07, 
    # 'day08': python_solutions.day08, 
    # 'day09': python_solutions.day09, 
    # 'day10': python_solutions.day10, 
    # 'day11': python_solutions.day11, 
    # 'day12': python_solutions.day12, 
    # 'day13': python_solutions.day13, 
    # 'day14': python_solutions.day14, 
    # 'day15': python_solutions.day15, 
    # 'day16': python_solutions.day16, 
    # 'day17': python_solutions.day17, 
    # 'day18': python_solutions.day18, 
    # 'day19': python_solutions.day19, 
    # 'day20': python_solutions.day20, 
    # 'day21': python_solutions.day21, 
    # 'day22': python_solutions.day22, 
    # 'day23': python_solutions.day23, 
    # 'day24': python_solutions.day24, 
    # 'day25': python_solutions.day25, 
}

def chooseProblem(day, part, inputfile): 
    returnfunction = f'day{day:02d}'
    f = function_mapping[returnfunction]
    return f(inputfile, part) 

def get_args():
    parser = argparse.ArgumentParser(description='Choose the day problem and input')
    parser.add_argument('day', metavar='DAY', type=int)
    parser.add_argument('part', metavar='PART', type=int, default=1, choices=[1, 2])
    parser.add_argument('--input', '-i', metavar='INPUT', type=str, help='Input filename. Must be txt.')

    return parser.parse_args()

if __name__ == '__main__': 
    args = get_args()
    if args.input == None: 
        inputfile = Path(inputfolder / f'day{args.day:02d}.txt')
    else: 
        inputfile = args.input 
    print(f'The input file path is: {inputfile.name} and is located in directory: {inputfile.parent}')
    print(f'The solution to problem of day {args.day} part {args.part} is {chooseProblem(args.day, args.part, inputfile)}. ')