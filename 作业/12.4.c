#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct person
{
    char *name;
    int cnt;
} person;

int main()
{
    person candidate[] = {
        {"zhang", 0},
        {"wang", 0},
        {"abstain", 0}};

    char a[128];

    const int hc = 3;
    const int person = 10;

    for (int i = 0; i < person; i++)
    {
        printf("您支持哪一位候选人?");

        if (!fgets(a, sizeof(a), stdin))
            break;

        for (char *p = a; *p; p++)
        {
            *p = tolower(*p);
            if (*p == '\n')
                *p = '\0';
        }

        int flag = 0;
        for (int i = 0; i < hc; i++)
        {
            if (strcmp(a, candidate[i].name) == 0)
            {
                candidate[i].cnt += 1;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            candidate[3].cnt += 1;
        }
    }

    printf("\n");
    printf("选举结果是: \n");
    for (int i = 0; i <= hc; i++)
        printf("%s\n%d\n\n", candidate[i].name, candidate[i].cnt);

    return 0;
}