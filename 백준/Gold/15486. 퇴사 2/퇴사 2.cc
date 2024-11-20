#include <iostream>
#include <algorithm>
using namespace std;

int time[1500001];
long long take[1500001];
long long table[1500002];

int main(){
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>time[i]>>take[i];
    }

    for(int i=n;i>=1;i--){
        if(i+time[i]-1<=n){
            //i번째 날에 스케줄을 잡을 수 있다면
            //스케줄을 잡지 않았을 때, 잡았을 때 최댓값 선택
            table[i] = max(table[i+1], table[i+time[i]]+take[i]);
        } else{
            //i번째 날 스케줄을 잡을 수 없다면
            //i+1 테이블 값 저장
            table[i] = table[i+1];
        }
    }
    cout<<table[1];
}