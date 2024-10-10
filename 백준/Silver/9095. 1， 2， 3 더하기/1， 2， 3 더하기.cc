#include <iostream>
#include <algorithm>
using namespace std;

int table[12];

int dp(int n){
    if(table[n]!=0) return table[n];

    if(table[n-1]==0) dp(n-1);
    if(table[n-2]==0) dp(n-2);
    if(table[n-3]==0) dp(n-3);
    table[n] = table[n-1]+table[n-2]+table[n-3];
    return table[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    table[1] = 1;
    table[2] = 2;
    table[3] = 4;

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<dp(n)<<'\n';
    }
}