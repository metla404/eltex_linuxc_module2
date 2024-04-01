#ifndef FUNC_IP_H
#define FUNC_IP_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

typedef struct
{
    uint8_t part1;
    uint8_t part2;
    uint8_t part3;
    uint8_t part4;
} IPAddress;

void ip_from_string(IPAddress* ip, const char* str);
uint32_t ip_to_int(const IPAddress* ip);
int check_in_subnet(const IPAddress* ip, const IPAddress* gateway, const IPAddress* mask); 
#endif