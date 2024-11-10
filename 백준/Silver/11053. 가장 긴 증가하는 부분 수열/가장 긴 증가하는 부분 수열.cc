#include <iostream>
#include <algorithm>
using namespace std;

int number[1001];
int table[1001]; //증가하는 부분 순열의 길이
int ans = 1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>number[i];
    }

    //앞선 내 현재 값보다 작은 것들 중 가장 table 값이 큰 것 + 1

    table[1] = 1;
    for(int i=2;i<=n;i++){        
        int max_value = 0;
        for(int j=i;j>=1;j--){
            if(number[i]>number[j]&&max_value<table[j]){
                max_value = table[j];
            }
        }
        
        table[i] = max_value + 1;
        if(ans<table[i]) ans = table[i];
    }
    cout<<ans;
}
