#include <iostream>
#include <queue>
using namespace std;

#define x first
#define y second

int board[1000][1000];
int vis[1000][1000];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    int M,N;
    cin>>M>>N;
    queue<pair<int,int>> q;

    for(int i=0;i<N;i++){
        for(int j=0; j<M; j++){
            cin>>board[i][j];
            if(board[i][j]==1){
                vis[i][j]=1;
                q.push({i,j});
            }
        }
    }
    
    int count=0;
    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        for(int i=0; i<4; i++){
            int x = cur.x+dx[i];
            int y = cur.y+dy[i];
            if(x<0||x>=N||y<0||y>=M) continue;
            if(board[x][y]==-1||vis[x][y]) continue;
            vis[x][y] = vis[cur.x][cur.y] + 1;
            if(vis[x][y]>count) count = vis[x][y];
            board[x][y] = 1;
            q.push({x,y});
        }
    }

    bool flag = true;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(board[i][j]==0){
                flag=false;
                break;
            }
        }
    }
    if(flag){
        if(count==0) cout<<count;
        else cout<<count-1;
    }
    else cout<<-1;
}