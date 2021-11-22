#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string rigth_vers(string str);
string delete_doubles(string str);
bool consonant(char letter);

const string cons = "bcdfghjklmnpqrstvwxzBCDFGHJKLMNPQRSTVWXZ";

int main()
{
    string input;

    cout << "read text from a file(input.txt), outputs the corrected version of the text to the output file(output.txt)" << endl;
    cout << "correct replacements: c - s(if in fronts is e,i,y), c - k(otherwise), q - k, qu - kv, x - ks, w - v, ph - f, you - u," << endl
    << "oo - u, ee - i, th - z and double consonants to single";

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    while(getline(fin, input))
    {
        if(input.length() > 100)
        {
            cout << "line size too large" << endl;
            break;
        }

        fout << rigth_vers(input) << endl;
    }

    fin.close();
    fout.close();
}

string delete_doubles(string str)
{
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == str[i + 1] && consonant(str[i]))
        {
            str.erase(i + 1, 1);
            i--;
        }
    }

    return(str);
}

bool consonant(char letter)
{
    for(int i = 0; cons[i] != '\0'; i++)
    {
        if(cons[i] == letter)
        {
            return(true);
        }
    }

    return(false);
}

string rigth_vers(string str)
{
    str = delete_doubles(str);

    string str_rigth = str;

    for(int i = 0, j = 0; str[i] != '\0'; i++, j++)
    {
        if(str[i] == 'c')
        {
            if(str[i + 1] == 'e'|| str[i + 1] == 'i' || str[i + 1] == 'y')
            {
                str_rigth[j] = 's';
            }
            else
            {
                str_rigth[j] = 'k';
            }
        }
        else if(str[i] == 'q')
        {
            if(str[i + 1] == 'u')
            {
                str_rigth[j] = 'k';
                str_rigth[j + 1] = 'v';

                j++;
                i++;
            }
            else
            {
                str_rigth[j] = 'k';
            }
        }
        else if(str[i] == 'x')
        {
            str_rigth.push_back(' ');

            str_rigth[j] = 'k';
            str_rigth[j + 1] = 's';

            j++;
        }
        else if(str[i] == 'w')
        {
            str_rigth[j] = 'v';
        }
        else if(str[i] == 'p' && str[i] == 'h')
        {
            str_rigth[j] = 'f';

            str_rigth.erase(j + 1, 1);
            i++;
        }
        else if(str[i] == 'y' && str[i + 1] == 'o' && str[i + 2] == 'u')
        {
            str_rigth[j] = 'u';

            str_rigth.erase(j + 1, 2);
            i = i + 2;
        }
        else if(str[i] == 'o' && str[i + 1] == 'o')
        {
            str_rigth[j] = 'u';

            str_rigth.erase(j + 1, 1);
            i++;
        }
        else if(str[i] == 'e' && str[i + 1] == 'e')
        {
            str_rigth[j] = 'i';

            str_rigth.erase(j + 1, 1);
            i++;
        }
        else if(str[i] == 't' && str[i + 1] == 'h')
        {
            str_rigth[j] = 'z';

            str_rigth.erase(j + 1, 1);
            i++;
        }
        else if(str[i] == 'C')       //Title letter
        {
            if(str[i + 1] == 'e'|| str[i + 1] == 'i' || str[i + 1] == 'y')
            {
                str_rigth[j] = 'S';
            }
            else
            {
                str_rigth[j] = 'K';
            }
        }
        else if(str[i] == 'Q')
        {
            if(str[j + 1] == 'u')
            {
                str_rigth[j] = 'K';
                str_rigth[j + 1] = 'v';

                j++;
                i++;
            }
            else
            {
                str_rigth[j] = 'K';
            }
        }
        else if(str[i] == 'X')
        {
            str_rigth.push_back(' ');

            str_rigth[j] = 'K';
            str_rigth[j + 1] = 's';

            j++;
        }
        else if(str[i] == 'W')
        {
            str_rigth[j] = 'V';
        }
        else if(str[i] == 'P' && str[i] == 'h')
        {
            str_rigth[j] = 'F';

            str_rigth.erase(j + 1, 1);
            i++;
        }
        else if(str[i] == 'Y' && str[i + 1] == 'o' && str[i + 2] == 'u')
        {
            str_rigth[j] = 'U';

            str_rigth.erase(j + 1, 2);
            i++;
        }
        else if(str[i] == 'O' && str[i + 1] == 'o')
        {
            str_rigth[j] = 'U';

            str_rigth.erase(j + 1, 1);
            i++;
        }
        else if(str[i] == 'E' && str[i + 1] == 'e')
        {
            str_rigth[j] = 'I';

            str_rigth.erase(j + 1, 1);
            i++;
        }
        else if(str[i] == 'T' && str[i + 1] == 'h')
        {
            str_rigth[j] = 'Z';

            str_rigth.erase(j + 1, 1);
            i++;
        }
        else
        {
            str_rigth[j] = str[i];
        }

    }

    str_rigth = delete_doubles(str_rigth);

    return(str_rigth);
}

