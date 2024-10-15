#include <iostream>
#include <vector>
using namespace std;

#define MOD 10007
int table[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin>>n;
    table[1] = 1;
    table[2] = 2;
    for(int i=3;i<=n;i++){
        table[i] = (table[i-1] + table[i-2]) % MOD;
    }
    cout<<table[n];
}