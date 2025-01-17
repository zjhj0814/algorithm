#include <iostream>
#include <queue>
using namespace std;

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> start; //{시작하는 시간} 오름차순
priority_queue<int, vector<int>, greater<int>> finish; //{끝나는 시간} 오름차순

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int s,t;
        cin>>s>>t;
        start.push({s,t});
    }

    int answer = 0;
    int curTime = 0;
    while(!start.empty()){
        int plus = 0;
        int minus = 0;
        while(!start.empty()&&start.top().first<=curTime){
            finish.push({start.top().second});
            start.pop();
            plus++;
        }
        while(!finish.empty()&&finish.top()<=curTime&&plus>minus){
            finish.pop();
            minus++;
        }
        answer += plus-minus;
        //cout<<curTime<<" "<<plus<<' '<<minus<<endl;
        if(!start.empty()) curTime = start.top().first;
    }

    cout<<answer;
}