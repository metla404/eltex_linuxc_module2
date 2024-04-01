#ifndef FUNC_RWX_H
#define FUNC_RWX_H
#include <stdio.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 20

void bin_to_perm(char binary[3][N], int oct[3], char letters[3][N]);
void oct_to_binary(int num, char binary[3][N], char letters[3][N]);
int dec_to_oct(int num);
bool num_check(const char *str);
void char_to_bin(char* letters, char binary[3][N]);
void perm_by_char(char *perm_in, char *perm, char *perm_bin, int index);
void get_group_perm(int index, char *perm_in, int *perm_to_change);
void modify_by_char(char *perm_in, char binary[3][N]);
void print_perms(char permissions[3][N], int oct[3], char binary[3][N]);
#endif