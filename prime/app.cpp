#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>


#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

int m=0;
int num=0;


static int isPrime(int n)
{
	//new algo
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
    int n = 0;
    struct stat fs;
    int fid = open(argv[1], O_RDONLY | O_DIRECT);
    size_t fsize = 100*32 * (512 + 1) * 4;
    char* fcontent = static_cast<char*>(mmap(NULL, fsize, PROT_READ,
                          MAP_FILE | MAP_PRIVATE | MAP_POPULATE,
                          fid, 0));



    do {
        // fgets and atoi
        if (*fcontent > '\n') {
            n = (n << 1) + (n << 3) + *fcontent++ - '0';
            continue;
        } else if (*fcontent++ == 0 && n == 0)
            break;

        // check primality of n
        printf("%d\n" , isPrime(n));

        n = 0;
    } while (1);


    close(fid);
    return 0;
}
