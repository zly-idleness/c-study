#include <iostream>

using namespace std;

const int N = 1000010;

int val[N], ne[N], idx, head;

void init()
{
    idx = 0;
    head = -1;
}

void add_to_head(int x)
{
    val[idx] = x;
    ne[idx] = head;
    head = idx++;
}

void insert(int k, int x)
{
    val[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx++;
}

void remove(int k)
{
    ne[k] = ne[ne[k]];
}

int main()
{
    int m;
    scanf("%d", &m);

    init();

    while (m--)
    {
        int k, x;
        char op;

        cin >> op;
        if (op == 'H')
        {
            cin >> x;
            add_to_head(x);
        }
        else if (op == 'D')
        {
            cin >> k;
            if (!k)
                head = ne[head];
            else
                remove(k - 1);
        }
        else
        {
            cin >> k >> x;
            insert(k - 1, x);
        }
    }

    for (int i = head; i != -1; i = ne[i])
        printf("%d ", val[i]);
}
