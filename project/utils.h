#ifndef UTILS_H
#define UTILS_H

#define _ISOC99_SOURCE
#define _POSIX_C_SOURCE 200112L
#define _GNU_SOURCE

#define ADDR_MAX_LEN 16
#define PORT_MAX_LEN 6

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <errno.h>

void errExit(const char* msg);
float strToRate(char* str);
void strToPortAddr(char* str, char* addr, in_port_t* port);
in_port_t strToPort(char* str);
unsigned long strToCapacity(char* str);

#endif
