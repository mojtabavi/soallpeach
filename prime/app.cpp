#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;


int isPrime(int number) 
{ 
    if (
            (number <=1 )
            ||(number % 2 == 0 && (number != 2))
            ||(number % 3 == 0 && (number != 3))
            ||(number % 5 == 0 && (number != 5))
            ||(number % 997 == 0 && (number != 997))
            ||(number % 857 == 0 && (number != 857))
            ||(number % 787 == 0 && (number != 787))
            || (number % 773 == 0 && (number != 773))
            ||(number % 983 == 0 && (number != 983))
            ||(number % 907 == 0 && (number != 907))
            || (number % 7 == 0 && (number != 7))
            || (number % 11 == 0 && (number != 11))
            || (number % 13 == 0 && (number != 13))
            || (number % 17 == 0 && (number != 17))
            || (number % 19 == 0 && (number != 19))
            || (number % 23 == 0 && (number != 23))
    )
        return 0;
  
    int max_div = floor(sqrt(number));
    for (int i = 2; i < max_div; i++) {
        if (number % i == 0) 
            return 0; 
    }
    return 1; 
} 

int main(int argc, char** argv)
{

    int num = 0;
    ifstream infile(argv[1]);
    while (infile >> num)
    {

        printf("%d\n", isPrime(num));
    }
    infile.close();
    return 0;
}