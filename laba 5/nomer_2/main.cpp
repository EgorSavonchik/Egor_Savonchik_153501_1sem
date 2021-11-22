#include <iostream>
#include <cmath>
#include "windows.h"

using namespace std;

int i = 0, meter = 0, meter_delta = 0;

int coun(int i, int top_limit, double* p_arr);

int main()
{
    int n;

    cout << "finds the number of array elements for which the condition is met (cos(B[i]^2 > 0) and (B[i] < 0)" << endl;
    cout  << "enter array length" << endl;

    while(!(cin >> n) || n <= 0)
    {
        cin.clear();
        cin.ignore(INT_MAX - 1, '\n');
        cout << "incorrect number" << endl;
    }

    cout << "enter array B" << endl;
    double* p_arr = new double[n];

    for(int j = 0; j < n; j++)
    {
        cout << "enter B[" << j << "]" << endl;
        while(!(cin >> p_arr[j]))
        {
            cin.clear();
            cin.ignore(INT_MAX - 1, '\n');
            cout << "incorrect number" << endl;
        }
    }

    cout << coun(i, n / 3, p_arr) + coun(i, n, p_arr);

    delete[] p_arr;
}

