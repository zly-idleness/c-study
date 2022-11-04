#include <iostream>

using namespace std;

const int N = 100010;

int stk[N], tt = 0;

int main()
{
    int m;
    scanf("%d", &m);

    while (m--)
    {
        string op;
        cin >> op;
        int x;
        if (op == "push")
        {
            cin >> x;
            stk[++tt] = x;
        }
        else if (op == "pop")
            tt--;
        else if (op == "empty")
            cout << (tt ? "NO" : "YES") << endl;
        else if (op == "query")
            cout << stk[tt] << endl;
    }
    return 0;
}