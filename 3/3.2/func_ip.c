#include "func_ip.h"

void ip_from_string(IPAddress* ip, const char* str) 
{
    sscanf(str, "%hhu.%hhu.%hhu.%hhu", &ip->part1, &ip->part2, &ip->part3, &ip->part4);
}

uint32_t ip_to_int(const IPAddress* ip) 
{
    return (ip->part1 << 24) | (ip->part2 << 16) | (ip->part3 << 8) | ip->part4;
}

int check_in_subnet(const IPAddress* ip, const IPAddress* gateway, const IPAddress* mask) 
{
    uint32_t ip_int = ip_to_int(ip);
    uint32_t gateway_int = ip_to_int(gateway);
    uint32_t mask_int = ip_to_int(mask);

    return (ip_int & mask_int) == (gateway_int & mask_int);
}
