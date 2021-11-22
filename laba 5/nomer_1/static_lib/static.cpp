#include <iostream>
#include <cmath>
#include "static.h"

using namespace std;

double value(int i)
{
    return(exp(-0.5 * i - 2 * M_PI ) - atan(i + 0.1));
}

double transf(double x)
{
    if (x > 0)
    {
        return(0.1);
    }
    else
    {
        return(x + 0.5);
    }
}

void out(double* p_arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << p_arr[i] << '\t';
    }
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

