#include <iostream>
#include <string>

using namespace std;

int counter(string str, char letter);
long long fact(int num);

int main()
{
    long long anag;
    string str, str_copy;

    cout << "displays the number of anagrams of the given word" << endl;
    cin >> str;

    str_copy = str;
    anag = fact(str.length());

    for(int i = 0 ; i < str.length(); i++)
    {
        if(counter(str, str[i]) > 1)
        {
            str.erase(i, 1);
            i--;
        }
    }

    for(int i = 0; i < str.length(); i++)
    {
        anag  /= fact(counter(str_copy, str[i]));
    }

    cout << anag;
}

int counter(string str, char letter)
{
    int coun = 0;

    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == letter)
        {
            coun++;
        }
    }

    return(coun);
}

long long fact(int num)
{
    long long ans = 1;

    for(int i = 1; i <= num; i++)
    {
        ans *= i;
    }

    return(ans);
}
