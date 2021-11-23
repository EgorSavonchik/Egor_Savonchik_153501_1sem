#include <iostream>
#include <cmath>

using namespace std;

long long func(unsigned long long a, unsigned long long n, long long mod);

int main()
{
    unsigned long long n, t, k;

    cout << "considers  (sum(i from 0 to n*(k-1)) f{n,i)) mod m," << endl <<
    "where function: f(0, 0) = 1, f(n, r) = sum(i from 0 to k - 1) (n-1, r-i) when [(n > 0) and (0 <= r < n*(k-1) + 1)]," << endl
    << "f(n, r) = 0 in otherwise" << endl;

    for(int i = 1; ; i++)
    {
        cout << "enter k n t" << endl;
        cin >> k >> n >> t;

        if(k + n + t > 0 && t < 10)
        {
            t = pow(10, t);
            cout << "case #" << i << " " << func(k, n, t) << endl;
        }
        else
        {
            return 0;
        }
    }
}

long long func(unsigned long long a, unsigned long long n, long long mod)
{
    if(!n)
    {
        return (1);
    }

    if(n % 2 == 1)
    {
        return(a * func((a * a) % mod, n / 2, mod) % mod);
    }

    return(func((a * a) % mod, n / 2, mod));
}
