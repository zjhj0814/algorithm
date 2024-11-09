#include <iostream>
#include <algorithm>
using namespace std;

//0: 연속값과 현재 값 비교 후 큰 값 저장
//1: 지금까지 나온 수 중에 가장 큰 값

int number[100001];
int table[100001][2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>number[i];
    }

    table[1][0] = table[1][1] = number[1];
    for(int i=2;i<=n;i++){
        table[i][0] = (table[i-1][0] + number[i]>number[i])? table[i-1][0] + number[i] : number[i];
        table[i][1] = max(table[i-1][1], table[i][0]);
    }
    cout<<table[n][1];
}
