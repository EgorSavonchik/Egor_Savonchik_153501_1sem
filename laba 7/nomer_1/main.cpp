#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int len(const string& a);
string bin_check();
void minus_del(string& str);

int main()
{
    string str, res = "";
    char sign;
    int decimal = 0;

    str = bin_check();

    if(str[0] == '-')
    {
        minus_del(str);
        sign = '-';
    }

    for(int i = 0; i < len(str); i++)
    {
        decimal += pow(9, i) * (str[len(str) - i - 1] - '0');
    }

    for(int i = 0; decimal ; i++)
    {
        if(decimal % 17 >= 10)
        {
            res = (char)(decimal % 17 + 'A' - 10) + res;
        }
        else
        {
            res = (char)(decimal % 17 + '0') + res;
        }

        decimal /= 17;
    }

    if(sign == '-')
    {
        cout << sign;
    }

    cout << res;
}

int len(const string& a)
{
    int len = 0;

    for( ; a[len] != '\0'; len++);

    return(len);
}

string bin_check()
{
    string str;
    bool normal = false;

    cin >> str;

    while(!normal)
    {
        normal = true;

        for(int i = 0; i < len(str); i++)
        {
            if(str[i] == '-' && i == 0)
            {
                continue;
            }
            else if(str[i] > '8' || str[i] < '0')
            {
                cin.clear();
                cin.ignore(INT_MAX -  1, '\n');
                cout << "incorrect number" << endl;

                cin >> str;

                normal = false;
            }
        }
    }

    return(str);
}

void minus_del(string& str)
{
    string res = "";

    for(int i = 1; i < len(str); i++)
    {
        res += str[i];
    }

    str = res;
}
