#include <iostream>
#include <string>

using namespace std;

int len(string str);
string bin_check();

int main()
{
    string direct, additional;

    cout << "Converts a number from a direct code to an additional one." << endl;
    cout << "enter direct code" << endl;

    direct = bin_check();

    additional = direct;

    if(direct[0] == '1')
    {
        for(int i = 1; direct[i] != '\0'; i++)
        {
            if(direct[i] == '0')
            {
                additional[i] = '1';
            }
            else
            {
                additional[i] = '0';
            }
        }

        additional[len(additional) - 1] += 1;

        for(int i = len(additional) - 1; additional[i] == '2'; i--)
        {
            additional[i] = '0';
            if(i != 0)
            {
                additional[i - 1] += 1;
            }
        }
    }

    cout << additional;

}

int len (string str)
{
    int i = 0;

    for( ; str[i] != '\0'; i++);

    return(i);
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
            if(str[i] > '1' || str[i] < '0')
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

