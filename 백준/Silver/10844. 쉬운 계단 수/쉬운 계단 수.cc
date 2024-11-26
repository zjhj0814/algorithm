#include <iostream>
#include <algorithm>
using namespace std;

#define MOD 1000000000

int table[101][10];

int main(){
    int n;
    cin>>n;

    for(int i=1;i<10;i++){ //1~9 1개
        table[1][i] = 1;
    }

    for(int i=2;i<=n;i++){
        table[i][0] = table[i-1][1];
        for(int j=1;j<=8;j++){
            table[i][j] = (table[i-1][j-1]+table[i-1][j+1])%MOD;
       }
        table[i][9] = table[i-1][8];
    }
    
    long long ans = 0;
    for(int i=0;i<10;i++){
        ans = (ans + table[n][i])%MOD;
    }
    cout<<ans;
}