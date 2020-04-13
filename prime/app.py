
from math import sqrt,floor
import sys

#file_name = sys.argv[1]

def is_prime2(num: int) -> bool:
    if ((num +1 ) % 6 == 0 or num == 2 or num == 3 or (num - 1) % 6 == 0):
        return True
    else:
        return False 


with open('number.txt') as input_numbers:
    for line in input_numbers:
        number = int(line)
        print(1 if is_prime2(number) else 0)