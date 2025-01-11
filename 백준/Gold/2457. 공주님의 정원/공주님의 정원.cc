#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//월 + 날을 어떻게 관리하지? -> 크기 비교만 가능하도록 파싱

vector<pair<int,int>> v;

bool compare(pair<int,int>& p1, pair<int,int>& p2){
    if(p1.first==p2.first) return p1.second>p2.second;
    return p1.first<p2.first;
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int m1,d1,m2,d2;
        cin>>m1>>d1>>m2>>d2;
        v.push_back({m1*100+d1, m2*100+d2});
    }
    sort(v.begin(), v.end(), compare);
    int answer = 0;
    int curDate = 301; //curDate부터 꽃이 피어야 함
    while(curDate<1201){
        int nxtDate = curDate;
        for(auto iter=v.begin(); iter!=v.end(); iter++){
            if(iter->first>curDate) break; //선택할 수 없는 꽃이면 그 이후는 패스
            if(nxtDate<iter->second) nxtDate = iter->second;
        }
        if(nxtDate==curDate){
            cout<<"0";
            return 0;
        }
        curDate = nxtDate;
        answer++;
    }
    cout<<answer;
    return 0;
}