#include <iostream>
#include <set>
#include <algorithm>
#include <stack>
using namespace std;

int n;
int hp[9]; //1~8까지 사용
int weight[9]; //1~8까지 사용
int answer = 0;
int egg; //살아있는 달걀의 수

void back(int count, int hand){ 
    //지금까지 깬 계란의 수
    //손에 쥐고 있는 계란의 인덱스 번호

    /*
    손에 들고 있는 계란으로 다른 계란을 친다.
    계란치기 실패, 
    - 손에 든 계란이 깨졋을 경우, 다시 원상복구하고 다음 오른 계란 쥐기(호출)
    - 모든 계란이 다 깨졌을 경우, 다시 원상복구하고 다음 오른 계란 쥐기(호출)
    계란치기 성공,
    - 부서진 계란수 +1, 다음 오른 계란 쥐기(호출) 
    */

    //cout<<count<<' '<<hand<<'\n';

    if(hand>n){
        if(answer<count) answer = count;
        return;
    }
    else if(hp[hand]<=0||count==(n-1)||count==n){
        //손에 쥘 계란이 이미 깨졌거나 모든 계란이 다 깨졌을 경우
        back(count,hand+1);
        return;
    }

    for(int i=1;i<=n;i++){
        if(hand==i) continue;
        else if(hp[i]>0){
            hp[hand] -= weight[i];
            hp[i] -= weight[hand];

            int tmp = 0;
            if(hp[hand]<=0) tmp++;
            if(hp[i]<=0) tmp++;

            back(count+tmp, hand+1);
            hp[hand] += weight[i];
            hp[i] += weight[hand];
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    egg = n;
    for(int i=1;i<=n;i++){
        cin>>hp[i];
        cin>>weight[i];
    }
    back(0,1);
    cout<<answer;
}