#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define N 50
#define FLT 2
#define INT 1
typedef struct Node
{
    int type;
    union
    {
        int ival;
        double dval;
    } dat;
} NodeType;

typedef struct stack
{
    NodeType date[N];
    int top;
} STACK;

void Push(STACK *stack, NodeType date);
NodeType Pop(STACK *stack);
NodeType OpInt(int d1, int d2, int op);
NodeType OpData(NodeType *d1, NodeType *d2, int op);
NodeType OpFloat(double d1, double d2, int op);

int main()
{
    char word[N];
    NodeType d1, d2, d3;
    STACK stack;
    stack.top = 0;
    while (scanf("%s", word) == 1 && word[0] != '#')
    {
        if (isdigit(word[0]))
        {
            if (strchr(word, '.') == NULL)
            {
                d1.type = INT;
                d1.dat.dval = atoi(word);
            }
            else
            {
                d1.type = FLT;
                d1.dat.dval = atof(word);
            }
            Push(&stack, d1);
            continue; //一直输入数字
        }
        else
        {
            d2 = Pop(&stack);
            d1 = Pop(&stack);
            d3 = OpData(&d1, &d2, word[0]);
            Push(&stack, d3);
        }
    }

    d1 = Pop(&stack);
    if (d1.type == 1)
    {
        printf("%d\n", d1.dat.ival);
    }
    else
    {
        printf("%.2f\n", d1.dat.dval);
    }
    return 0;
}

void Push(STACK *stack, NodeType date)
{

    memcpy(&stack->date[stack->top], &date, sizeof(NodeType));
    stack->top = stack->top + 1;
}
NodeType Pop(STACK *stack)
{
    stack->top = stack->top - 1;
    return stack->date[stack->top];
}
NodeType OpInt(int d1, int d2, int op)
{
    NodeType res;
    switch (op)
    {
    case '+':
        res.dat.ival = d1 + d2;
        break;
    case '-':
        res.dat.ival = d1 - d2;
        break;
    case '*':
        res.dat.ival = d1 * d2;
        break;
    case '/':
        if (d2 != 0)
        {
            res.dat.ival = d1 / d2;
            break;
        }
        else
        {
            printf("erro\n");
            exit(1);
        }
    }
    res.type = INT;
    return res;
}
NodeType OpFloat(double d1, double d2, int op)
{
    NodeType res;
    switch (op)
    {
    case '+':
        res.dat.dval = d1 + d2;
        break;
    case '-':
        res.dat.dval = d1 - d2;
        break;
    case '/':
        if (d2 == 0)
        {
            printf("error: cannot divide 0");
            exit(1);
        }
        else
        {
            res.dat.ival = d1 / d2;
            break;
        }
    case '*':
        res.dat.dval = d1 * d2;
        break;
    }
    res.type = FLT;
    return res;
}

NodeType OpData(NodeType *d1, NodeType *d2, int op)
{
    NodeType res;
    double dv1, dv2;
    if (d1->type == d2->type)
    {
        if (d1->type == INT)
        {
            res = OpInt(d1->dat.ival, d2->dat.ival, op);
        }
        else
        {
            res = OpFloat(d1->dat.dval, d2->dat.dval, op);
        }
    }
    else
    {
        dv1 = (d1->type == INT) ? d1->dat.ival : d1->dat.dval;
        dv2 = (d2->type == INT) ? d2->dat.ival : d2->dat.dval;
    }
    return res;
}
