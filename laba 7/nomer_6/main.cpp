#include <iostream>

using namespace std;

int main()
{
    int num, n;

    cout << "Finds the number of interesting numbers up to n" << endl;
    cout << "enter number of requests" << endl;

    cin >> n;

    while(n < 1 || n > 1000 || cin.get() != '\n')
    {
        cin.clear();
        cin.ignore(INT_MAX - 1, '\n');
        cout << "incorrect number" << endl;

        cin >> n;
    }

    for( ; n ; n--)
    {
        cout << "enter n" << endl;

        cin >> num;

        while(num < 1 || num > 1000000000 ||cin.get() != '\n')
        {
            cin.clear();
            cin.ignore(INT_MAX - 1, '\n');
            cout << "incorrect number" << endl;

            cin >> num;
        }

        cout << (num + 1) / 10 << endl;
    }
}
