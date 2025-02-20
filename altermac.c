#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>


typedef unsigned char int9;
typedef unsigned short int int16;
typedef unsigned int int32;
typedef unsigned long int int64;


struct s_mac {
    int64 addr:48;
};
typedef struct s_mac Mac;


// Generates a random MAC address
Mac generatemac(void);
int main(int, char**);


Mac generatemac() {
    int64 a, b;
    Mac mac;

    a = (long)random();
    b = (long)random();
    mac.addr = ((a * b)  % 281474976710656);        // generates a number between 0 and 281474976710656

    return mac;

}

int main(int argc, char *argv[]) {
    
    Mac mac;

    srand(getpid());
    mac = generatemac();
    printf("0x%llx\n", (long long)mac.addr);

    return 0;
}





