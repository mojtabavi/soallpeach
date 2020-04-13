
from math import sqrt,floor
import sys

file_name = sys.argv[1]

def is_prime2(num: int) -> bool:
    if num <= 1:
        return False

    if num == 2:
        return True

    if num > 2 and num % 2 == 0:
        return False

    max_div = floor(sqrt(num))
    for i in range(3, 1 + max_div, 2):
        if num % i == 0:
            return False

    return True

with open(file_name) as input_numbers:
    for line in input_numbers:
        number = int(line)
        print(1 if is_prime2(number) else 0)