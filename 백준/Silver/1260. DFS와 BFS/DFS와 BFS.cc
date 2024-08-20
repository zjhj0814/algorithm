#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;

//인접 행렬로 그래프 구현 (+인접 리스트로 표현)
int board1[1001][1001];
int board2[1001][1001];
//노드 방문 유무
int vis[1001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m,v, tmp1, tmp2;
    cin>>n>>m>>v;
    for(int i=0;i<m;i++){
        cin>>tmp1>>tmp2;
        board1[tmp1][tmp2] = board1[tmp2][tmp1] = 1; //tmp1<->tmp2
    }
    copy(&board1[0][0],&board1[1000][1001],&board2[0][0]);
    //dfs
    stack<int> s;
    s.push(v);
    while(!s.empty()){
        int cur = s.top(); s.pop();
        if(vis[cur]!=1) cout << cur << ' ';
        vis[cur] = 1;
        for (int i = n; i >= 1; i--){
            if (board1[cur][i] != 0){
                board1[cur][i] = board1[i][cur] = 0;
                if (vis[i]) continue;
                s.push(i);
            }
        }
    }
    cout<<endl;
    //bfs
    fill(&vis[0],&vis[1001],0);
    queue<int> q;
    q.push(v);
    vis[v] = 1;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        cout<<cur<<' ';
        for(int i=1;i<=n;i++){
            if(board2[cur][i]!=0){
                board2[cur][i] = board2[i][cur] = 0;
                if(vis[i]==1) continue;
                q.push(i);
                vis[i] = 1;
            }
        }
    }
}
