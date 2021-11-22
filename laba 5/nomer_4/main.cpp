#include <iostream>

using namespace std;

int F(int n);
int S(int p, int q);
int check();

int main()
{
    int p, q;

    cout << "evaluates the given recursive function" << endl;
    cout << "enter p q" << endl;
    p = check();
    q = check();

    if( p < 0 || q < 0)
    {
        return(0);
    }

    cout << S(p, q);
}

int F(int n)
{
    if(n % 10 > 0)
    {
        return(n % 10);
    }
    else if(n == 0)
    {
        return(0);
    }
    else
    {
        F(n / 10);
    }
}

int S(int p, int q)
{
    int sum = 0;

    for(int i = p; i <= q; i++)
    {
        sum += F(i);
    }

    return(sum);
}

int check()
{
    int n;

    cin >> n;

    while(cin.get() != '\n')
    {
        cin.clear();
        cin.ignore(INT_MAX - 1, '\n');
        cout << "incorrect number" << endl;

        cin >> n;
    }

    return(n);
}
