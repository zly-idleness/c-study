#include <stdio.h>
#include <stdlib.h>

void strdel2(char *dst, char const *src, char x);
void strdel1(char dst[], char const src[], char x);

int main() 
{
    char A[15];
    char test[] = "abcabcabcabc";

    strdel1(A, test, 'a');
    printf("%s\n", A);
    
    strdel1(A, test, 'b');
    printf("%s\n", A);
    
    strdel1(A, test, 'c');
    printf("%s\n", A);
    

    strdel2(A, test, 'a');
    printf("%s\n",A);
    
    strdel2(A, test, 'b');
    printf("%s\n", A);
    
    strdel2(A, test, 'c');
    printf("%s\n",A);

    return 0;
}
void strdel1(char dst[], char const src[], char x)
{
    int pos = 0;
    for (int i = 0; src[i] != '\0'; i++) {
        if (src[i] != x)
            dst[pos++] = src[i];
    }
    dst[pos] = '\0';
}

void strdel2(char *dst, char const *src, char x)
{
    while (*src != '\0') {
        if ((*dst = *src++) != x)
            *dst++;
    }
    *dst = '\0';
}
