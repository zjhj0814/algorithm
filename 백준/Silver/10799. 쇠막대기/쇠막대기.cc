#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    int count = 0;
    stack<char> s;
    cin >> str;
    for (int i = 0; i < (int)str.size(); i++)
    {
        char c = str[i];
        if (c == '(')
        { // c=='('인 경우
            s.push(c);
        }
        else
        { // c==')'인 경우
            //레이저인 경우
            if (str[i - 1] == '(')
            {
                s.pop();
                count+=s.size();
            }
            else
            {
                if (s.top() == '(')
                {
                    count++;
                    s.pop();
                }
                else
                {
                    s.push(c);
                }
            }
        }
    }
    cout << count;
}