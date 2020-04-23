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
#define limit 100000
#define wlimit 317 // sqrt(limit)

unsigned char numbers[limit];


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

    int x, y, z, h, g, j;
    for (x=1; x<wlimit; x++)
        for (y=1; y<wlimit; y++) {
            h = x*x;
            g = y*y;
            z = (h << 2) + g;
            if (z < limit) {
                j = z % 60;
                if (j == 1 || j == 13 || j == 17 || j == 29 ||
                    j == 37 || j == 41 || j == 49 || j == 53)
                    numbers[z] = !numbers[z];
            }
            z = z - h;
            if (z < limit) {
                j = z % 60;
                if (j == 7 || j == 19 || j == 31 || j == 43)
                    numbers[z] = !numbers[z];
            }
            z = z - (g << 1);
            if (x > y && z < limit) {
                j = z % 60;
                if (j == 11 || j == 23 || j == 47 || j == 59)
                    numbers[z] = !numbers[z];
            }
        }

    for (x=7; x<wlimit; x++)
        if (numbers[x] == 1) {
            z = x*x;
            for (y=1; y*z<limit; y++)
                numbers[y*z] = 0;
        }

    numbers[1] = numbers[4] = 0;
    numbers[2] = numbers[3] = numbers[5] = 1;



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
        if (n<limit)
            x = numbers[n];
        else {
            x = isPrime(n);
        }
        
        printf("%d\n" , x);

        n = 0;
    } while (1);


    close(fid);
    return 0;
}
