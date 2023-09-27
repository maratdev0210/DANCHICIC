#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

string reverse(string const &s)
{
    string rev;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        rev = rev.append(1, s[i]);
    };

    return rev;
}

string perevod(int num)
{
    string s = "";
    while (num > 0)
    {
        // int -> string
        s += to_string(num % 2);
        num /= 2;
    }
    string snum = reverse(s);
    return snum;
}
int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    string str;
    fin >> str;
    string num = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (isdigit(str[i]))
        {
            num += str[i];
        }
        else
        {
            if (num != "")
            {

                // string -> int with #include <cstdlib>
                int inum = atoi(num.c_str());
                //
                cout << perevod(inum);
                num = "";
            }
            cout << str[i];
        }
    }
    if (num != "")
    {
        fout << perevod(atoi(num.c_str()));
    }
    return 0;
}
