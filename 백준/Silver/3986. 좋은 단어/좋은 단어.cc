#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, count=0;
    string str;
    cin>>N;
    while(N--){
        cin>>str;
        stack<char> s;
        bool isValid = true;
        for(char c:str){
            if(s.empty()){
                s.push(c);
            }
            else{
                if(s.top()==c){
                    s.pop();
                }
                else{
                    s.push(c);
                }
            }
        }
        if(s.size()==0) count++;
    }
    cout<<count;
}
