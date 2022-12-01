# Advent of Code 2022
My C++ wannabe and Python solutions for the advent of code 2022. 
Link here: [Advent of Code 2022](https://adventofcode.com/2022/)

## How to use this repository? 
This repository is mainly personal as I am learning while solving the daily puzzles from AoC 2022. You can use the solutions in this repository for comparison. 
In order to do so, you can look at the [C++ solutions](#c-solutions) or the [Python solutions](#python-solutions). 
To make the different solutions work, don't forget to put your input in the input folder with the name `day02.txt` if your input is for the puzzle of day 2. (The input texts that are already present are simple copy/paste of my own inputs.)

## C++ Solutions 
The C++ solutions are available in the folder `cpp_solutions`. The code for each solution is available in the folder corresponding to the day. Use the Makefile for the compilation of the solution in the corresponding folder. 

Please ignore the files `solve.cpp`, `Dailypuzzle.cpp`, `Dailypuzzle.hpp` and the `Makefile` in `cpp_solutions` as they mostly serve as templates for each daily solution. Especially, DO NOT try to compile the Makefile. (You will end up with an error most probably.)

## Python Solutions 
The Python solutions are available in the folder `python_solutions`. This package is used in the file `solve.py` at the root. 

Use the following command prompt to obtain the solution of problem day 1. 
```
python solve.py 1 
``` 
You can also specify the part (1 or 2) of the problem you want the solution to if you don't want all of the answers revealed. 
```
python solve.py 1 -p 1
``` 