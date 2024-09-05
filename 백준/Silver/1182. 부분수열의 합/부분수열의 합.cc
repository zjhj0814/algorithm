#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;

int number[20];
int sum = 0;
int cnt = 0;
int n,s;

void back(int next){
    if(next==n){
        //cout<<" 마지막 노드\n";
        return;
    }
    for(int i=next;i<n;i++){
        //cout<<"next는"<<next<<", i는"<<i;
        sum += number[i];
        //cout<<"+"<<number[i];
        //cout<<"="<<sum<<' ';
        if(sum==s){
            cnt++;
            //cout<<" 발견!";
        }
        back(i+1);
        sum -= number[i];
        //cout<<"-"<<number[i];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>s;
    for(int i=0;i<n;i++){
        cin>>number[i];
    }
    back(0);
    //cout<<endl;
    cout<<cnt;

}