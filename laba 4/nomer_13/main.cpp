#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int ucheck();

int main()
{
    int n, sockets = 0;
    cout << "finds the numbers of free sockets" << endl;
    cout << "number of extension cords" << endl;
    n = ucheck();

    cout << "number of sockets in extension cords" << endl;

    int* p_arr = new int [n];

    for(int i = 0; i < n; i++)
    {
        p_arr[i] = ucheck();
    }

    for(int i = 0; i < n; i++)
    {
        sockets  += p_arr[i] - 1;
    }

    cout << sockets;

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



