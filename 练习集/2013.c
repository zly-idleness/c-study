#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()

{
    char str[105] = {'0'};
    fgets(str, 100, stdin);
    for (int i = 0; i < 100; i++)
    {
        if (isdigit(str[i]))
            printf("%10d\n", str[i] - '0');
    }
    return 0;
}