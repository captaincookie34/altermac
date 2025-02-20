#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <netinet/in.h>
#include <net/if_arp.h>

typedef unsigned char int9;
typedef unsigned short int int16;
typedef unsigned int int32;
typedef unsigned long int int64;


struct s_mac {
    int64 addr:48;
};
typedef struct s_mac Mac;


// Generates a random MAC Address
Mac generatemac() {
    int64 a, b;
    Mac mac;

    a = (long)random();
    b = (long)random();
    
    // generates a number between 0 and 281474976710656
    mac.addr = ((a * b)  % 281474976710656);

    return mac;

}

bool changeMac(int *inface, Mac mac) {
    struct ifreq ir;
    int fd, ret;

    fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_IP);
    assert(fd > 0);

    strncpy(ir.ifr_ifrn.ifrn_name, (char *)inface, (IFNAMSIZ - 1));

    ir.ifr_ifru.ifru_hwaddr.sa_family = ARPHRD_ETHER;

    memcpy(ir.ifr_ifru.ifru_hwaddr.sa_data, &mac, 6);

    ret = ioctl(fd, SIOCSIFHWADDR, &ir);
    // free(p);
    close(fd);

    if (!ret) return true;
    else return false;
}

int main(int argc, char *argv[]) {
    
    Mac mac;
    int *inface;

    if(argc < 2) {
        fprintf(stderr, "Usage: %s INTERFACE\n", *argv);
        return -1;
    } else {
        inface = (int*)argv[1];
    }

    srand(getpid());
    mac = generatemac();

    if(changeMac(inface, mac)) printf("0x%llx\n", (long long)mac.addr);
    else assert_perror(errno);

    return 0;
}
