#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int multi=1, sum=0;
    string str;
    stack<char> s;
    cin>>str;
    for(int i=0; i<(int)str.size(); i++){
        char c=str[i];
        if(c=='('){
            multi*=2;
            s.push(c);
        }
        else if(c==')'){
            if(s.empty()||s.top()!='('){ //잘못된 문자열
                sum=0;
                break;
            }
            else if(str[i-1]=='('){
                sum+=multi;
                multi/=2;
                s.pop();
            }
            else{
                //sum+=multi;
                multi/=2;
                s.pop();
            }
        }
        else if(c=='['){
            multi*=3;
            s.push(c);
        }
        else{
            if(s.empty()||s.top()!='['){
                sum=0;
                break;
            }
            else if(str[i-1]=='['){
                sum+=multi;
                multi/=3;
                s.pop();
            }
            else{
                //sum+=multi;
                multi/=3;
                s.pop();
            }
        }
        //cout<<sum<<" "<<multi<<" "<<s.size()<<'\n';
    }
    if(s.empty()) cout<<sum;
    else cout<<0;
}