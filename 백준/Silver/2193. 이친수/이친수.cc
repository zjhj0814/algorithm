#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

long long table[91][2]; //n자리 이친수를 구하는 비용, 이때 0으로 끝날때, 1로 끝날때

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    //1 - 1
    //2 - 10 - 1
    //3 - 100, 101 - 2
    //4 - 1001, 1010, 1000 - 3
    //5 - 10010, 10100, 10101, 10000, 10001 - 5

    int n;
    cin>>n;
    
    table[1][0] = 0, table[1][1] = 1;

    for(int i=2;i<=n;i++){
        table[i][0] = table[i-1][0] + table[i-1][1];
        table[i][1] = table[i-1][0];
    }

    cout<<table[n][0]+table[n][1];

}
