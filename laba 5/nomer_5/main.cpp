#include <iostream>
#include <cmath>

using namespace std;

long long fast_degree_on_mod(unsigned long long a, unsigned long long n, long long mod);

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
            cout << "case #" << i << " " << fast_degree_on_mod(k, n, t) << endl;
        }
        else
        {
            return 0;
        }
    }
}

long long fast_degree_on_mod(unsigned long long a, unsigned long long n, long long mod)
{
    unsigned long long out = 1, len;

    mod = pow(10, mod);
    a = a % mod;

    len = log(n) / log(2) + 1;

    int* bin_back = new int[len];
    unsigned long long* lefrovers = new unsigned long long[len];

    for(int i = 0; i < len; i++)
    {
        bin_back[i] = n % 2;
        n /= 2;
    }

    lefrovers[0] = a;

    for(int i = 1; i < len; i++)
    {
        lefrovers[i] = (lefrovers[i - 1] * lefrovers[i - 1]) % mod;
    }

    for(int i = 0; i < len; i++)
    {
       if(bin_back[i])
       {
           out = (out * lefrovers[i]) % mod; // out *= (int)pow(lefrovers[i], bin_back[i]) почемy
       }
    }

    return(out % mod);

    delete[] bin_back;
    delete[] lefrovers;
}





