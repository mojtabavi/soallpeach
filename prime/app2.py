
from math import sqrt,floor
import sys



with open('number.txt') as input_numbers:
    for line in input_numbers:
        line = line.replace('\n', '')
        print(line)