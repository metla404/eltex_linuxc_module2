#include <stdio.h>
#include "func_ip.h"

int main(int argc, char* argv[]) 
{
    srand(time(NULL));
    if (argc != 4) 
    {
        printf("Правило использования: %s <шлюз> <маска> <число_пакетов>\n", argv[0]);
        return 1;
    }

    IPAddress gateway, mask, ip;
    ip_from_string(&gateway, argv[1]);
    ip_from_string(&mask, argv[2]);
    int num_packets = atoi(argv[3]);

    int same_subnet_count = 0;
    int diff_subnet_count = 0;

    for (int i = 0; i < num_packets; i++) 
    {
        ip.part1 = rand() % 256;
        ip.part2 = rand() % 256;
        ip.part3 = rand() % 256;
        ip.part4 = rand() % 256;

        if (check_in_subnet(&ip, &gateway, &mask)) 
        {
            same_subnet_count++;
        } 
        else 
        {
            diff_subnet_count++;
        }
    }

    printf("Пакеты, предназначенные для узлов своей подсети: %d (%.2f%%)\n",
           same_subnet_count, (float)same_subnet_count / num_packets * 100);
    printf("Пакеты, предназначенные для узлов других подсетей.: %d (%.2f%%)\n",
           diff_subnet_count, (float)diff_subnet_count / num_packets * 100);

    return 0;
}
