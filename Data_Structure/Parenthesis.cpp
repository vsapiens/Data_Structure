#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

struct Bracket
{
    string str;
    int pos;
};
bool checkOpening(char c)
{
    switch (c)
    {
    case '{':
    case '[':
    case '(':
        return true;
    }
    return false;
}

bool checkClosing(char c)
{
    switch (c)
    {
    case '}':
    case ']':
    case ')':
        return true;
    }
    return false;
}

bool checkPair(char a, stack<Bracket> st)
{
    if ((a == '}' && st.top().str[0] == '{') || (a == ']' && st.top().str[0] == '[') || (a == ')' && st.top().str[0] == '('))
        return true;

    return false;
}
int main()
{
    stack<Bracket> st;
    string data;
    getline(cin, data);
    Bracket br;

    for (int i = 0; i < data.length(); ++i)
    {
        char a;
        a = data[i];
        if (checkOpening(a))
        {
            br.str = a;
            br.pos = i;
            st.push(br);
        }
        if (checkClosing(a))
        {
            if (st.empty())
            {
                cout << i + 1 << endl;
                return 0;
            }

            else if (!checkPair(a, st))
            {
                cout << i + 1 << endl;
                return 0;
            }
            else if (checkPair(a, st))
                st.pop();
        }
    }
    if (st.empty())
    {
        cout << "Success" << endl;
        return 0;
    }
    cout << st.top().pos + 1 << endl;
    return 0;
}