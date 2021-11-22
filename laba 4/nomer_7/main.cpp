#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int ucheck();

int main()
{
    int num, num1, i, leng = 0;

    cout << "finds the number of digits of a number and finds what number is in the digit i" << endl;
    cout << "enter number" << endl;
    num = ucheck();

    cout << "enter digit i" << endl;
    i = ucheck();

    num1 = num;

    while (num > 0)
    {
        num /= 10;
        leng++;
    }

    int* p_arr = new int [leng];

    for (int n = 0; n < leng; n++)
    {
        p_arr[n] = num1 % 10;
        num1 /= 10;
    }

    if (i < leng)
    {
        cout << "number of digits " << leng << " number is in the digit i " << p_arr[i];
    }
    else
    {
        cout << "i goes beyond the number";
    }

    delete[] p_arr;
}


int ucheck() //examination for + number
{
    int x = 0, i, m = 0;
    string n;

    cin >> n;

    while (m == 0)
    {
        for (i = 0; i < (int)n.length(); i++)
        {
            if (!((n[i] - '0') >= 0 and (n[i] - '0') <= 9))
            {
                cout << "incorrect number" << endl;

                m = 1;
                break;
            }
        }
        if (m == 1)
        {
            m = i = 0;

            cout << "enter right number" << endl;
            cin >> n;
        }

        if (i == (int)n.length())
        {
            for (int a = 0; a < (int)n.length(); a++)
            {
                x += (n[a] - '0') * pow(10, n.length() - a -1);
            }
            m = 1;
        }
    }

    return(x);
}

