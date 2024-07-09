#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int dx[] = {1,2,-1,-2,-1,-2,1,2};
int dy[] = {2,1,2,1,-2,-1,-2,-1};

int vis[300][300];
queue<pair<int,int>> q;

int bfs(queue<pair<int,int>>& q, int N, int tmpx, int tmpy){
    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        for(int i=0; i<8; i++){
            int x = cur.first + dx[i];
            int y = cur.second + dy[i];
            if(x<0||x>=N||y<0||y>=N) continue;
            if(vis[x][y]!=0) continue;
            vis[x][y] = vis[cur.first][cur.second] + 1;
            if(x==tmpx&&y==tmpy) return 0;
            q.push({x,y});
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, N;
    cin>>T;
    while(T--){
        fill(&vis[0][0],&vis[299][300],0);
        while(!q.empty()){
            q.pop();
        }
        cin>>N;

        int tmpx,tmpy;
        cin>>tmpx>>tmpy;
        vis[tmpx][tmpy] = 1;
        q.push({tmpx,tmpy});
        cin>>tmpx>>tmpy;

        bfs(q, N, tmpx, tmpy);

        cout<<vis[tmpx][tmpy]-1<<'\n';
    }
}