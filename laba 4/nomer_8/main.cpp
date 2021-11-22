#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int ucheck();
int check();

int main()
{
    int n, minim, maxim, minim_i, maxim_i, counter, j = 0;

    cout << "replaces the values between the maximum and minimum member of an array with zeros" << endl << "if most of the array is zero then deletes it" << endl;
    cout << "enter the number of members in the array" << endl;
    n = ucheck();

    cout << "enter array containing " << n << " numbers" << endl;
    int* p_arr = new int [n];

    for (int i; i < n; i++)
    {
        p_arr[i] = check();
    }

    minim = p_arr[0];
    maxim = p_arr[0];
    minim_i = 0;
    maxim_i = 0;

    for (int i = 0; i < n; i++)
    {
        if (p_arr[i] > maxim)
        {
            maxim = p_arr[i];
            maxim_i = i;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (p_arr[i] < minim)
        {
            minim = p_arr[i];
            minim_i = i;
        }
    }

    if (minim_i > maxim_i)
    {
        for (int i = maxim_i + 1; i < minim_i; i++)
        {
            p_arr[i] = 0;
            counter++;
        }
    }
    else
    {
        for (int i = minim_i + 1; i < maxim_i; i++)
        {
            p_arr[i] = 0;
            counter++;
        }
    }


    if (counter > (n / 2))
    {
        int* p_new = new int [counter];

        for(int i = 0; i < n; i++)
        {
            if (p_arr[i] != 0)
            {
                p_new[j] = p_arr[i];
                j++;
            }
        }

        for(int i = 0; i < j; i++)
        {
            cout << p_new[i] << " ";
        }

        delete[] p_new;
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            cout << p_arr[i] << " ";
        }
    }

    delete[] p_arr;
}


int check()    //examination for +- number
{
    int x = 0, i, m = 0, minis = 0;
    string n;

    cin >> n;

    while (m == 0)
    {
        minis = 0;

        if (n[0] == '-')
        {
            minis = 1;
            n[0] = '0';
        }

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

    if (minis == 0)
    {
        return(x);
    }
    else
    {
        return(-x);
    }
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

