#include <iostream>
using namespace std;

int table[1000001];

int main(){
    int n;
    cin>>n;
    int number;
    int answer = 0;
    for(int i=1;i<=n;i++){
        cin>>number;
        table[number] = table[number-1] + 1;
        if(answer<table[number]) answer = table[number];
    }
    cout<<n-answer;
}