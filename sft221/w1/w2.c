#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void concat(char dest[], const char src[]);

int main()
{
    char str1[100] = "Seneca, ";
    char str2[100] = "College";
    printf("Before concatenation:\n");
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);

    concat(str1, str2);

    printf("\nAfter concatenation:\n");
    printf("str1: %s\n", str1);
   
    return 0;
}
void concat(char dest[], const char src[])
{
    int dp = 0, sp = 0;
    if (dest != NULL)
    {
        for (dp = 0; dest[dp] != '\0'; dp++);
        if (src != NULL)
        {
            for (sp = 0; src[sp] != '\0'; sp++)
            {
                dest[dp++] = src[sp];
            }
            dest[dp] = '\0';
        }
    }
}