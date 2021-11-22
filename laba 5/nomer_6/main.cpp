#include <iostream>

using namespace std;

long long del(long long n);
long long check();

int main()
{
    long long n;

    cout << "find f(1) + f(2) + ... + f(n), where f(n) this is greatest odd divisor a number n" << endl;
    cout << "enter n" << endl;

    n = check();

    cout << del(n);
}

long long del(long long n)
{
    long long k = (n + 1) / 2;

    if(!n)
    {
        return (0);
    }
    else
    {
        return(k * k + del(n / 2));
    }
}

long long check()
{
    long long n;

    cin >> n;

    while(n <= 0 || cin.get() != '\n')
    {
        cin.clear();
        cin.ignore(INT_MAX - 1, '\n');
        cout << "incorrect number" << endl;

        cin >> n;
    }

    return(n);
}

