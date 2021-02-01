#ifndef UTILS_H
#define UTILS_H

#define _ISOC99_SOURCE
#define _POSIX_C_SOURCE 200112L
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <errno.h>

#include "consts.h"

void errExit(const char* msg);
void usageExit(const char* programName, const char* msg);

float strToRate(char* str);
void strToPortAddr(char* str, char* addr, in_port_t* port);
in_port_t strToPort(char* str);
unsigned long strToCapacity(char* str);

#endif
