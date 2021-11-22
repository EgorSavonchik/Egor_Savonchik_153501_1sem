#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int fast_degree_on_mod(int a, long long n, int mod);
int check();

int main()
{
    long long l;
    int n, m, option;
    string str_pre, str_post, exchen;
    bool label;

    cout << "finds the number(by module) of possible strings by suffix and prefix" << endl;
    cout << "enter the number of requests" << endl;

    n = check();

    for(int coun = 0; coun < n; coun++)
    {
        label = false;
        option = 0;

        cout << "enter string length" << endl;
        l = check();
        cout << "enter module" << endl;
        m = check();

        cout << "enter suffix and prefix" << endl;
        cin >> str_pre >> str_post;

        if(str_pre.length() + str_post.length() == l)
        {
            cout << 2 << endl;
        }
        else if(str_pre.length() + str_post.length() > l)
        {
            for(int i = 0; i < max(str_pre.length(), str_post.length()) && !label; i++)
            {
                for(int num = 0; str_pre[i + num] == str_post[num] && str_pre.length() - i <= str_post.length() && !label; num++)
                {
                    if(num + i == str_pre.length() - 1)
                    {
                        option++;
                        label = true;
                    }
                }
            }

            exchen = str_pre;
            str_pre = str_post;
            str_post = exchen;
            label = false;

            for(int i = 0; i < max(str_pre.length(), str_post.length()) && !label; i++)
            {
                for(int num = 0; str_pre[i + num] == str_post[num] && str_pre.length() - i <= str_post.length() && !label; num++)
                {
                    if(num + i == str_pre.length() - 1)
                    {
                        option++;
                        label = true;
                    }
                }
            }

            cout << option;
        }
        else
        {
            cout << fast_degree_on_mod(26 , l - str_pre.length() - str_post.length(), m) << endl;
        }
    }
}

int fast_degree_on_mod(int a, long long n, int mod)
{
    int out = 1, len;

    len = log(n) / log(2) + 1;

    int* bin_back = new int[len];
    int* lefrovers = new int[len];

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
           out = (out * lefrovers[i]) % mod;
       }
    }

    return(out * 2 % mod);

    delete[] bin_back;
    delete[] lefrovers;
}

int check()
{
    int n;

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
