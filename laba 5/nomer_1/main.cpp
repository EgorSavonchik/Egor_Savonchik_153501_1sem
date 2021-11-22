#include <iostream>
#include <cmath>
#include "static_lib/static.h"

using namespace std;

void out(double* p_arr, int n);
double transf(double x);
double value(int i);
int check();

int main()
{
    int n;
    cout << "calculate array of length n values according the formula x(i) = e^(-0.5*i-2*p) - arctg(i + 0.1), where i = 0,1...,n" << endl
    << "and p this is pi(3.14...), after all negative elements increase by 0.5, and replace positive by 0.1" << endl;

    cout << "enter n" << endl;
    n = check();

    double* p_arr = new double[n];

    for(int i = 0; i < n; i++)
    {
        p_arr[i] = value(i);
    }

    out(p_arr, n);
    cout << endl;

    for(int i = 0; i < n; i++)
    {
        p_arr[i] = transf(p_arr[i]);
    }

    out(p_arr, n);

    delete[] p_arr;
}

