#include <iostream>
#include <cmath>

using namespace std;

void trans_out(int decimal);
int int_check();

int main()
{
    int n, decimal  = 0;
    char sign = '\0';

    n = int_check();

    if(n < 0)
    {
        n = -n;
        sign ='-';
    }

    for(int i = 0; n ; i++)
    {
        decimal += pow(9, i) * (n % 10);
        n /= 10;
    }

    if(sign == '-')
    {
        cout << '-';
    }

    if(decimal)
    {
        trans_out(decimal);
    }
    else
    {
        cout << 0;
    }
}

void trans_out(int decimal)
{
    if(decimal)
    {
        if(decimal % 17 >= 10)
        {
            trans_out(decimal / 17);
            cout << (char)(decimal % 17 + 'A' - 10);
        }
        else
        {
            trans_out(decimal / 17);
            cout << decimal % 17;
        }
    }
}

int int_check()
{
    int num;
    bool normal;

    while(!normal)
    {
        normal = true;

        cin >> num;

        if(cin.get() != '\n')
        {
            cin.clear();
            cin.ignore(INT_MAX -  1, '\n');
            cout << "incorrect number" << endl;

            normal = false;
        }


        for(int i = num; i != 0; i = i / 10)
        {
            if(i % 10 == 9)
            {
                cin.clear();
                cin.ignore(INT_MAX -  1, '\n');
                cout << "incorrect number" << endl;

                normal = false;
            }
        }
    }

    return(num);
}
