#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s)
{
    stack<int> stck;
    for (char it : s)
    {
        if (it == ')')
        {
            if (stck.top() != '(')
                return false;
            stck.pop();
        }
        else if (it == ']')
        {
            if (stck.top() != '[')
                return false;
            stck.pop();
        }
        else if (it == '}')
        {
            if (stck.top() != '{')
                return false;
            stck.pop();
        }
        stck.push(it);
    }
    return true;
}

int main()
{
    string s = "{[]}";
    cout << isValid(s) << endl;
    return 0;
}