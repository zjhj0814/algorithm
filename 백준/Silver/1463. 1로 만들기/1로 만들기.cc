#include <iostream>
#include <algorithm>
using namespace std;

int table[1000001];

int dp(const int n){
    //cout<<n<<endl;
    if(n==1) return 0; //base condition

    if(table[n]!=-1) return table[n];
    else{
        if(table[n-1]==-1) dp(n-1);
        table[n] = table[n-1] + 1;

        if(n%3==0){
            if(table[n/3]==-1) dp(n/3);
            if(table[n/3]+1<table[n]) table[n] = table[n/3] + 1;
        }

        if(n%2==0){
            if(table[n/2]==-1) dp(n/2);
            if(table[n/2]+1<table[n]) table[n] = table[n/2] + 1;
        }
        return table[n];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    fill(&table[0], &table[1000001],-1);
    table[1] = 0;
    int n;
    cin>>n;
    cout<<dp(n);
}