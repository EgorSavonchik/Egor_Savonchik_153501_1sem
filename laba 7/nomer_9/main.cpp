#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int check();

int main()
{
    string three = "";
    char tr;
    int decimal, len;

    cout << "Converts a number from decimal to ternary without zero(contain 1, 2, 3)" << endl;
    cout << "enter number" << endl;

    cin >> decimal;

    while(decimal < 1 || decimal > 2 * pow(10, 9) || cin.get() != '\n')
    {
        cin.clear();
        cin.ignore(INT_MAX - 1, '\n');
        cout << "incorrect number" << endl;

        cin >> decimal;
    }

    len = log(decimal) / log(3) + 1;

    while(decimal)
    {
        three += decimal % 3 + '0';
        decimal /= 3;
    }

    for(int i = 0; i < len / 2; i++)
    {
        tr = three[i];
        three[i] = three[len - i - 1];
        three[len - i - 1] = tr;
    }

    for(int i = 0; three[i] != '\0'; i++)
    {
        if(three[i + 1] == '0' && three[i] != '\0')
        {
            three[i] = three[i] - 1;
            three[i + 1] = '3';

            i = 0;
        }
    }

    for(int i = 0; three[i] != '\0'; i++)
    {
        if(three[i] != '0')
        {
            cout << three[i];
        }
    }

    cout << endl;
}
