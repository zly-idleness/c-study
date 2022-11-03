#include <stdio.h>
#include <string.h>
int main()
{
    int array[40][3];
    char str[40][40] = {"hello"};

    int m, grade;
    int t1 = 0, t2 = 0, t3 = 0;

    printf("Input the total number of the students(n<40):\n");
    scanf("%d", &m);

    printf("Input student¡¯s ID and score as: MT  EN  PH:\n");
    for (int i = 0; i < m; i++)
    {
        scanf("%s", str[i]);
        for (int j = 0; j < 3; j++)
        {
            getchar();
            scanf("%d", &array[i][j]);
        }
    }

    printf("Counting Result:\n");

    printf("Student¡¯s ID\t  MT \t  EN \t  PH \t SUM \t AVER\n");

    for (int a = 0; a < m; a++)
    {
        int sum = 0;
        printf("%12s\t", str[a]);
        for (int b = 0; b < 3; b++)
        {
            sum = sum + array[a][b];
            printf("%4d\t", array[a][b]);
        }

        printf("%4d\t", sum);

        printf("%5.1f\n", (float)sum / 3.0);
    }

    for (int i = 0; i < m; i++)
    {
        t1 = t1 + array[i][0];
        t2 = t2 + array[i][1];
        t3 = t3 + array[i][2];
    }

    printf("SumofCourse \t");

    printf("%4d\t%4d\t%4d\t", t1, t2, t3);

    printf("\nAverofCourse\t");

    printf("%4.1f\t%4.1f\t%4.1f\t", (float)t1 / m, (float)t2 / m, (float)t3 / m);

    return 0;
}