#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<int> operand;
stack<char> plusminus;

int main(){
    string str;
    cin>>str;
    int i = 0;
    while(i<str.size()){
        if(str[i]=='+'||str[i]=='-'){
            operand.push(stoi(str.substr(0,i)));
            plusminus.push(str[i]);

            str = str.substr(i+1);
            i = 0;
        }
        i++;
    }
    operand.push(stoi(str));

    int answer = 0;
    int temp = 0;

    while(!operand.empty()){
        temp += operand.top(); operand.pop();
        if(plusminus.empty()){
           answer += temp; 
        }
        else if(plusminus.top()=='-'){
            answer -= temp;
            temp = 0;
        }
        plusminus.pop();
    }
    cout<<answer;
}