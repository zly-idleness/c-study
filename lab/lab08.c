#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct record
{
    char id[5 + 1];
    char name[10 + 1];
    int income;
    int expenses;
} record;

void input();
void Sir();
void search();
void per();
void list_m();
void list_a();
void exit_program();
void quick_sort(record *list, int l, int r);

void print_header()
{
    printf("%10s%12s%10s%10s\n", "ID", "Name", "Income", "expenses");
    printf("  --------"
           "  ----------"
           "  --------"
           "  --------"
           "\n");
}

void print_record(record const *p)
{
    printf("%10s%12s%10d%10d\n", p->id, p->name, p->income, p->expenses);
}

void (*func[])() = {

    exit_program,
    input,
    Sir,
    search,
    per,
    list_m,
    list_a,

};

size_t cnt = 0;
record *list = 0;

int main()
{
    while (1)
    {
        printf("1.Input record\n");
        printf("2.Sort and list records in reverse order by user name\n");
        printf("3.Search records by user name\n");
        printf("4.Calculate and list per capita income and expenses\n");
        printf("5.List records which have more expenses than per capita expenses\n");
        printf("6.List all records\n");
        printf("0.Exit\n");

        int choice = -1;
        do
        {
            printf("  Please enter your choice: ");
        } while (scanf("%d", &choice) != 1 || !(0 <= choice && choice <= 6));

        func[choice]();
    }
    return 0;
}

void quick_sort(record *list, int l, int r)
{
    if (l >= r)
        return;

    int i = l - 1, j = r + 1;
    int x = list[(l + r + 1) >> 1].name[0] - '0';

    while (i < j)
    {
        do
            i++;
        while (list[i].name[0] - '0' < x);
        do
            j--;
        while (list[j].name[0] - '0' > x);
        if (i < j)
        {
            record t = list[i];
            list[i] = list[j];
            list[j] = t;
        }
    }
    quick_sort(list, i, r);
    quick_sort(list, l, i - 1);
}

void input()
{
    printf("Please let me know the amount\n");
    scanf("%zu", &cnt);
    list = calloc(cnt, sizeof(struct record));
    size_t i = 0;
    record *now = 0;
    for (now = list, i = 0; i < cnt; now++, i++)
    {
        scanf("%5s", &now->id);
        scanf("%10s", &now->name);
        scanf("%d", &now->income);
        scanf("%d", &now->expenses);
    }
}
void Sir()
{
    quick_sort(list, 0, cnt - 1);
    for (size_t i = 0; i < cnt - i; i++)
    {
        record t = list[i];
        list[i] = list[cnt - i - 1];
        list[cnt - i - 1] = t;
    }
    print_header();
    for (size_t i = 0; i < cnt; i++)
    {
        print_record(list + i);
    }
}
void search()
{
    char name1[10];
    quick_sort(list, 0, cnt - 1);
    printf("Please tell me the name : \n");
    scanf("%s", &name1);
    for (size_t pos = 0; pos < cnt; pos++)
    {
        if (name1[0] - '0' == list[pos].name[0] - '0')
        {
            int flag = strcmp(name1, list[pos].name);
            if (!flag)
            {
                print_record(&list[pos]);
            }
            else
            {
                printf("Not found\n");
                return;
            }
        }
    }
    return;
}
void per()
{
    int sum1 = 0;
    int sum2 = 0;

    for (size_t i = 0; i < cnt; i++)
    {
        sum1 += list[i].income;
        sum2 += list[i].expenses;
    }

    printf("Per capita income is : %.2f\n", 1.0 * sum1 / cnt);
    printf("Per capita expenses is : %.2f\n", 1.0 * sum2 / cnt);
}
void list_m()
{
    int sum2 = 0;

    for (size_t i = 0; i < cnt; i++)
        sum2 += list[i].expenses;
    double avg = 1.0 * sum2 / cnt;
    for (size_t i = 0; i < cnt; i++)
    {
        if (list[i].expenses > avg)
            print_record(list + i);
    }
}
void list_a()
{
    print_header();
    for (size_t i = 0; i < cnt; i++)
    {
        print_record(list + i);
    }
}
void exit_program(void)
{
    exit(0);
}
// lalalalalalalal