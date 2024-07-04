#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int dz[] = {-1,1};

int board[100][100][100];
int vis[100][100][100];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(board[0][0],board[0][0]+100*100*100,-1);

    int M,N,H;
    queue<pair<int,pair<int,int>>> q;
    cin>>M>>N>>H;

    int tmp, flag=1;
    for(int i=0; i<H; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<M; k++){
                cin>>tmp;
                if(tmp==0) flag = 0;
                else if(tmp==1){
                    vis[i][j][k] = 1;
                    q.push({i,{j,k}});
                }
                board[i][j][k] = tmp;
            }
        }
    }
    if(flag){
        cout<<0;
        return 0;
    }

    while(!q.empty()){
        pair<int,pair<int,int>> cur = q.front(); q.pop();
        for(int i=0; i<4; i++){
            int x = cur.second.first + dx[i];
            int y = cur.second.second + dy[i];
            int z = cur.first;
            if(x<0||x>=N||y<0||y>=M) continue;
            if(vis[z][x][y]||board[z][x][y]!=0) continue;
            vis[z][x][y] = vis[z][cur.second.first][cur.second.second] + 1;
            board[z][x][y] = 1;
            q.push({z,{x,y}});
        }
        for(int i=0; i<2; i++){
            int x = cur.second.first;
            int y = cur.second.second;
            int z = cur.first + dz[i];
            if(z<0||z>=H) continue;
            if(vis[z][x][y]||board[z][x][y]!=0) continue;
            vis[z][x][y] = vis[cur.first][x][y] + 1;
            board[z][x][y] = 1;
            q.push({z,{x,y}});
        }
    }

    int day = 1;
    for(int i=0; i<H; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<M; k++){
                if(board[i][j][k]==0){
                    cout<<-1;
                    return 0;
                }
                else if(vis[i][j][k]>day) day = vis[i][j][k];
            }
        }
    }    
    cout<<day-1;
}