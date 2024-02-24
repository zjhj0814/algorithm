#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <list>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    list<char> ed;
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        ed.push_back(str[i]);
    }
    list<char>::iterator cursor = ed.end();
    int num;
    char arg;
    cin >> num;
    while (num--)
    {
        cin >> str;
        if (str == "L") //왼쪽으로
        {
            if(cursor==ed.begin()) continue;
            cursor--;
        }
        else if (str == "D") //오른쪽으로
        {
            if(cursor==ed.end()) continue;
            cursor++;
        }
        else if (str == "B") //커서 왼쪽 문자 삭제
        {
            if(cursor==ed.begin()) continue;
            else cursor=ed.erase(--cursor);
        }
        else if (str == "P") //커서 왼쪽에 추가
        {
            cin >> arg;
            ed.insert(cursor,arg);
        }
    }
    for(char c:ed){
        cout<<c;
    }
}