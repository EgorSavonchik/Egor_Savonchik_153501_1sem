#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int sum = 0, num = 0;
    string str;

    cout << "finds the sum of the numbers in a string" << endl;
    cin >> str;

    for(int i = 0; i < str.length(); i++)
    {
        for(int j = 0; isdigit(str[i]) && i < str.length(); i++, j++)
        {
            num = ((int)str[i] - '0') + num * pow(10, j);
        }

        sum += num;
        num = 0;
    }

    cout << sum;
}
