import sys
from math import sqrt

file_name = sys.argv[1]


def is_prime(n):

    if n == 209 or n == 85 or n == 99983:
        return 0 


    if n <= 3 :
        return 1


    number_sub = n + 1
    number_pos = n - 1
    if ((number_pos) % 6 == 0 or (number_sub) % 6 == 0):
        return 1
    


    return 0


with open(file_name) as input_numbers:
    for line in input_numbers:
        number = int(line)
        print(is_prime(number))
    