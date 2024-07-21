#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int board[300][300];
int vis[300][300];
queue<pair<int,int>> q;

void bfs(int n,int m){ //하나의 빙산 녹이고 방문한 곳은 체크
    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        for(int i=0;i<4;i++){
            int x = cur.first + dx[i];
            int y = cur.second + dy[i];
            if(x<0||x>=n||y<0||y>=m) continue;
            if(vis[x][y]==1) continue;

            if(board[x][y]==0&&board[cur.first][cur.second]>0) board[cur.first][cur.second]--; //빙산 녹이기
            else if(board[x][y]!=0){
                vis[x][y] = 1;
                q.push({x,y});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
        }
    }

    int year = -1;
    while(true){
        year++;
        //새로운 bfs할 때마다 count, flag, vis 초기화
        int count = 0;
        bool flag = true;
        fill(&vis[0][0],&vis[299][300],0);
        for(int i=1;i<(n-1);i++){
            for(int j=1;j<(m-1);j++){
                if(board[i][j]!=0&&vis[i][j]!=1){ //빙산 발견
                    count++; flag = false;
                    vis[i][j] = 1;
                    q.push({i,j});
                    bfs(n,m);
                }
            }
        }
        if(count>=2){
            cout<<year;
            break;
        }
        if(flag){ //빙산이 다 녹을 때까지 분리되지 않으면
            cout<<0;
            break;
        }
    }
}
