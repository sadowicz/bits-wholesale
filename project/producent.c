#define _POSIX_C_SOURCE 2
#define _XOPEN_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>

#include "utils.h"

void parseArgs(int argc, char** argv, float* prodRate, char* addr, in_port_t* port);

int main(int argc, char* argv[])
{
    if(argc != 4)
        usageExit(argv[0], "-p <float> [<addr>:]port");

    float prodRate = 0.f;
    char addr[ADDR_MAX_LEN] = {0};
    in_port_t port = 0;

    parseArgs(argc, argv, &prodRate, addr, &port);

    printf("rate: %f\naddress: %s\nport: %d\n", prodRate, addr, port);

    return 0;
}

void parseArgs(int argc, char** argv, float* prodRate, char* addr, in_port_t* port)
{
    int opt;

    while((opt = getopt(argc, argv, "-:p:")) != -1)
    {
        switch(opt)
        {
            case 'p':
                *prodRate = strToRate(optarg);
                break;
            case 1:
                strToPortAddr(argv[optind - 1], addr, port);
                break;
            case ':':
                errExit("parseArgs: Argument requires value");
                break;
            case '?':
                errExit("parseArgs: Unrecognized argument");
                break;
            default: break;
        }
    }
}