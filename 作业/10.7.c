#include <stdio.h>
#include <string.h>

void strrev1(char dst[], char const src[]);
void strrev2(char *dst, char const *src);

int main() 
{
    char const test[] = "abcdef";
    char A[10]; 

    memset(A, 0, sizeof(A));
    strrev1(A, test);
    printf("%s\n", A);

    memset(A, 0, sizeof(A));
    strrev2(A, test);
    printf("%s\n", A);

    return 0;
}

void strrev1(char dst[], char const src[]) 
{
    size_t const len = strlen(src);
    for (int i = len - 1; i >= 0; i--) {
        dst[len - 1 - i] = src[i];
    }
    dst[len] = '\0';
}

void strrev2(char *dst, char const *src)
{
    char const * const beg = src;
    while (*src != '\0')
        src++;
    src -= 1; // 此时 src 指向 \0, 往后缩一位
    
    while (src >= beg)
        *dst++ = *src--;
    *dst = '\0';
}