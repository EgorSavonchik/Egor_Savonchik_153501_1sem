#include <iostream>
#include <cmath>
#include "main.h"

using namespace std;

int i = 0, meter = 0, meter_delta = 0;

int coun(int i, int top_limit, double* p_arr)
{
    meter = meter_delta;

    if (cos(pow(p_arr[i], 2)) > 0 and p_arr[i] < 0)
    {
        meter++;
        meter_delta++;
    }

    i++;

    if (i >= top_limit - 1)
    {
        meter_delta = 0;
        return(meter);
    }
    cout << "qwe" << endl;
    coun(i, top_limit, p_arr);
}
