#include <iostream>
#include <string>

using namespace std;

int main()
{
    string lit_trans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int num_trans[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    int arabic;
    string res;

    cout << "Converts a number from Arabic to Roman system." << endl;
    cout << "enter arabic number(0 < n < 4000)" << endl;

    cin >> arabic;

    while(arabic < 1 || arabic > 3999 || cin.get() != '\n')
    {
        cin.clear();
        cin.ignore(INT_MAX - 1, '\n');
        cout << "incorrect number" << endl;

        cin >> arabic;
    }

    for(int i = 0; arabic; i++)
    {
        if(arabic - num_trans[i] >= 0)
        {
            res = res + lit_trans[i];
            arabic -= num_trans[i];
            i--;
        }
    }

    cout << res;
}
