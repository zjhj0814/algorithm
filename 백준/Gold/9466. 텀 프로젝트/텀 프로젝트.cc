#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;

int student[100001];
int state[100001];

const int NOT_VIS = -1;
const int CYCLE = 0;

void bfs(int i){
    const int initial = i;
    int cur = initial;
    while(state[cur] == NOT_VIS){
        state[cur] = initial;
        cur = student[cur];
    }
    while(state[cur] == initial){
        state[cur] = CYCLE;
        cur = student[cur];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t,n;
    cin>>t;
    while(t--){
        int count = 0;
        fill(&student[0],&student[100001],0);
        fill(&state[0],&state[100001],-1);
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>student[i];
        }
        for(int i=1;i<=n;i++){
            if(state[i]==NOT_VIS) bfs(i);
        }
        for(int i=1;i<=n;i++){
            //cout<<state[i]<<" ";
            if(state[i]!=CYCLE) count++;
        }
        cout<<count<<'\n';
    }
}
