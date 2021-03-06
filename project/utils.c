#include "utils.h"

void errExit(const char* msg)
{
    fprintf(stderr, "ERROR: %s\n", msg);
    exit(1);
}

void usageExit(const char* programName, const char* msg)
{
    fprintf(stderr, "USAGE: %s %s\n", programName, msg);
    exit(1);
}

float strToRate(char* str)
{
    char* endptr = 0;
    errno = 0;

    float res = strtof(str, &endptr);

    if(errno || *endptr || res < 0.f)
        errExit("strToRate: Unable to convert string to rate (unnegative float)");

    return res;
}

void strToPortAddr(char* str, char* addr, in_port_t* port)
{
    char* portStart = strstr(str, ":");

    if(!portStart)
    {
        portStart = str;    // str consists of port only
        memcpy(addr, "localhost", strlen("localhost") + 1);
    }
    else
    {
        size_t addrLen = strlen(str) - strlen(portStart);

        if(addrLen > ADDR_MAX_LEN - 1)
            errExit("IP adress too long");

        memcpy(addr, str, addrLen);
        portStart++;    // set portStart after ':'
    }

    *port = strToPort(portStart);
}

in_port_t strToPort(char* str)
{
    char* endptr = 0;
    errno = 0;

    long res = strtol(str, &endptr, 10);

    if(errno || *endptr || res < 0 || res > 65535)
        errExit("strToPort: Unable to  convert string to port number");

    return (in_port_t)res;
}

unsigned long strToCapacity(char* str)
{
    char* endptr = 0;
    errno = 0;

    unsigned long res = strtoul(str, &endptr, 10);

    if(errno || *endptr)
        errExit("strToCapacity: Unable to  convert string to storehouse capacity");

    return res;
}