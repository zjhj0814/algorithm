#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

long long table[101];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin>>t;
    
    table[1] = table[2] = table[3] = 1;
    table[4] = table[5] = 2;

    for(int i=6;i<=100;i++){
        table[i] = table[i-1] + table[i-5];
    }

    while(t--){
        int n;
        cin>>n;
        cout<<table[n]<<'\n';
    }
}