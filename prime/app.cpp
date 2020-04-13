#include <iostream>
#include <fstream>
#include <string>
using namespace std;


bool isPrime(int n) 
{ 
    // Corner case 
    if (n <= 1) 
        return false; 
  
    // Check from 2 to n-1 
    for (int i = 2; i < n; i++) 
        if (n % i == 0) 
            return false; 
  
    return true; 
} 

int main(int argc, char** argv)
{

    int num = 0;
    ifstream infile(argv[1]);
    while (infile >> num)
    {

        isPrime(num) ? cout << "1" <<endl:  
                       cout << "0" <<endl; 
    }
    infile.close();
    return 0;
}