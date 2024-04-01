#include "func_rwx.h"

void bin_to_perm(char binary[3][N], int oct[3], char letters[3][N]) 
{
    for (int i = 0; i < 3; i++) 
    {
        if(strstr(binary[i], "000")) 
        {
            strcpy(letters[i], "---");
            oct[i] = 0;
        }
        else if(strstr(binary[i], "001")) 
        {
            strcpy(letters[i], "--x");
            oct[i] = 1;
        }
        else if(strstr(binary[i], "010")) 
        {
            strcpy(letters[i], "-w-");
            oct[i] = 2;
        }
        else if(strstr(binary[i], "011")) 
        {
            strcpy(letters[i], "-wx");
            oct[i] = 3;
        }
        else if(strstr(binary[i], "100")) 
        {
            strcpy(letters[i], "r--");
            oct[i] = 4;
        }
        else if(strstr(binary[i], "101")) 
        {
            strcpy(letters[i], "r-x");
            oct[i] = 5;
        }
        else if(strstr(binary[i], "110")) 
        {
            strcpy(letters[i], "rw-");
            oct[i] = 6;
        }
        else if(strstr(binary[i], "111")) 
        {
            strcpy(letters[i], "rwx");
            oct[i] = 7;
        }
    }
}

void oct_to_binary(int num, char binary[3][N], char letters[3][N]) 
{
    int number;
    for(int i = 2; i >= 0; i--) 
    {
        number = num % 10;
        switch(number) 
        {
            case 0:
                strcpy(binary[i], "000");
                strcpy(letters[i], "---");
                break;
            case 1:
                strcpy(binary[i], "001");
                strcpy(letters[i], "--x");
                break;
            case 2:
                strcpy(binary[i], "010");
                strcpy(letters[i], "-w-");
                break;
            case 3:
                strcpy(binary[i], "011");
                strcpy(letters[i], "-wx");
                break;
            case 4:
                strcpy(binary[i], "100");
                strcpy(letters[i], "r--");
                break;
            case 5:
                strcpy(binary[i], "101");
                strcpy(letters[i], "r-x");
                break;
            case 6:
                strcpy(binary[i], "110");
                strcpy(letters[i], "rw-");
                break;
            case 7:
                strcpy(binary[i], "111");
                strcpy(letters[i], "rwx");
                break;
        }
        num /= 10;
    }
}

int dec_to_oct(int num) 
{
    int oct[N];
    int i = 0;

    if(num <= 7)
        return num;

    while(num / 8 != 0) 
    {
        oct[i] = num % 8;
        num/=8;
        i++;
    }

    num = oct[2]*100 + oct[1]*10 + oct[0];
    return num;
}

bool num_check(const char *str) 
{
    while (*str) { if (!isdigit(*str++)) {return false;} }
    return true;
}

void char_to_bin(char* letters, char binary[3][N]) 
{
    int bin_c = 0;

    for(int i = 2; i < strlen(letters); i+=3) 
    {
        if(letters[i-2] == '-' && letters[i-1] == '-' && letters[i] == '-')
            strcpy(binary[bin_c], "000");
        
        else if(letters[i-2] == '-' && letters[i-1] == '-' && letters[i] == 'x')
            strcpy(binary[bin_c], "001");
        
        else if(letters[i-2] == '-' && letters[i-1] == 'w' && letters[i] == '-')
            strcpy(binary[bin_c], "010");
        
        else if(letters[i-2] == '-' && letters[i-1] == 'w' && letters[i] == 'x')
            strcpy(binary[bin_c], "011");
        
        else if(letters[i-2] == 'r' && letters[i-1] == '-' && letters[i] == '-')
            strcpy(binary[bin_c], "100");
        
        else if(letters[i-2] == 'r' && letters[i-1] == '-' && letters[i] == 'x')
            strcpy(binary[bin_c], "101");
        
        else if(letters[i-2] == 'r' && letters[i-1] == 'w' && letters[i] == '-')
            strcpy(binary[bin_c], "110");
        
        else if(letters[i-2] == 'r' && letters[i-1] == 'w' && letters[i] == 'x')
            strcpy(binary[bin_c], "111");

        bin_c++;
    }
}

void perm_by_char(char *perm_in, char *perm, char *perm_bin, int index) 
{
    int counter = 0;
    for(int i = index+1; i < strlen(perm_in); i++) 
    {
        perm[counter] = perm_in[i];
        counter++;
    }

    switch(counter) 
    {
        case 1:
            switch(perm[0]) 
            {
                case 'x':
                    strcpy(perm_bin, "001");
                    break;
                case 'w':
                    strcpy(perm_bin, "010");
                    break;
                case 'r':
                    strcpy(perm_bin, "100");
                    break;
                default:
                    printf("Ошибка ввода. Код: counter_case_1\n");
                    exit(1);
            }
            break;

        case 2:
            if(strstr(perm, "wx"))
                strcpy(perm_bin, "011");
            
            else if(strstr(perm, "rx"))
                strcpy(perm_bin, "101");
            
            else if(strstr(perm, "rw"))
                strcpy(perm_bin, "110");
            
            else 
            {
                printf("Ошибка ввода. Код: counter_case_2\n");
                exit(1);
            }
            break;

        case 3:
            if(strstr(perm, "rwx"))
                strcpy(perm_bin, "111");
            
            else
            {
                printf("Ошибка ввода. Код: counter_case_3\n");
                exit(1);
            }
            break;

        default:
            printf("Ошибка ввода. Код: counter_default\n");
            exit(1);
    }
}

void get_group_perm(int index, char *perm_in, int *perm_to_change) 
{

    for (int i = 0; i < index; i++) 
    {
        if(perm_in[i] == 'a') 
        {
            for(int j = 0; j < 3; j++)
                perm_to_change[j] = 1;
            break;
        }
        
        else if(perm_in[i] == 'u')
            perm_to_change[0] = 1;
        
        else if(perm_in[i] == 'g')
            perm_to_change[1] = 1;
        
        else if(perm_in[i] == 'o')
            perm_to_change[2] = 1;
    }
}

void modify_by_char(char *perm_in, char binary[3][N]) 
{
    char perm[N];
    char perm_bin[N];
    char operation = '\0';
    int perm_to_change[] = {0, 0, 0};
    int index = 0;

    for (int i = 0; i < strlen(perm_in); i++) 
    {
        if (perm_in[i]=='='||perm_in[i]=='+'||perm_in[i]=='-') 
        {
            index = i;
            operation = perm_in[i];
            break;
        }
    }

    get_group_perm(index, perm_in, perm_to_change);

    perm_by_char(perm_in, perm, perm_bin, index);

    switch(operation) 
    {
        case '+':
            for(int i = 0; i < 3; i++) 
            {
                if(perm_to_change[i] == 1) 
                {
                    for(int j = 0; j < 3; j++) 
                    {
                        if((binary[i][j] == '0') && (perm_bin[j] == '1'))
                            binary[i][j] = perm_bin[j];
                    }
                }
            }
            break;

        case '-':
            for(int i = 0; i < 3; i++) 
            {
                if(perm_to_change[i] == 1) 
                {
                    for(int j = 0; j < 3; j++) 
                    {
                        if(binary[i][j] == '1' && perm_bin[j] == '1')
                            binary[i][j] = '0';
                    }
                }
            }
            break;

        case '=':
            for(int i = 0; i < 3; i++) 
            {
                if(perm_to_change[i] == 1)
                    strcpy(binary[i], perm_bin);
            }
            break;

        default:
            printf("Плохой аргумент\n");
            exit(0);
    }
}

void print_perms(char permissions[3][N], int oct[3], char binary[3][N]) 
{
    printf("\nБуквенное представление: ");
    for (int i = 0; i < 3; i++)
        printf("%s", permissions[i]);

    printf("\nЦифровое представление: ");
    for (int i = 0; i < 3; i++)
        printf("%d", oct[i]);

    printf("\nБинарное представление: ");
    for (int i = 0; i < 3; i++)
        printf("%s", binary[i]);

    printf("\n");
}