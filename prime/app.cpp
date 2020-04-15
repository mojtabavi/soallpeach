#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

int m=0;
int num=0;


static int isPrime(int n)
{
    if (n <= 3)
        return 1;
    if (n % 2 == 0 || n % 3 == 0)
        return 0;
    int max_div = (int)sqrt(n) +1 ;
    for (m = 5; m < max_div; m = m + 6)
    {
        if (n % m == 0 || n % (m + 2) == 0)
            return 0;
    }
    return 1;
    
}




int main(int argc, char** argv)
{
    ifstream infile(argv[1]);
    while (infile >> num)
    {

        printf("%d\n", isPrime(num));
    }

    
    infile.close();
    return 0;
}
