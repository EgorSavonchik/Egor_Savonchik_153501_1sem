#include <iostream>
#include <string>

using namespace std;

bool palindrom(string str);

int main()
{
    string str, str_copy;
    int max_pal = 0;

    cout << "finds the maximum length of a longest non-palindrome substring" << endl;
    cin >> str;

    for(int i = 0; i < str.length(); i++)
    {
        for(int j = 0; j < str.length(); j++)
        {
            str_copy = str;

            str_copy.erase(i, j);

            if(!palindrom(str_copy))
            {
                if(str_copy.length() >= max_pal)
                {
                    max_pal = str_copy.length();
                }
            }
        }
    }

    cout << max_pal;
}

bool palindrom(string str)
{
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] != str[str.length() - i - 1])
        {
            return(false);
        }
    }

    return(true);
}
