#include <iostream>
#include <cstdlib>

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
    string str;
    cin >> str;
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
        cout << perevod(atoi(num.c_str()));
    }
    cout << endl;
    return 0;
}