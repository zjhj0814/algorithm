#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int board[1000][1000];
int vis[1000][1000];
int vis_copy[1000][1000];

int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(&board[0][0], &board[999][1000], 1);

    queue<pair<int,int>> q, wall;

    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0; j<m; j++){
            char tmp; cin>>tmp;
            board[i][j] = tmp - '0';
            if(board[i][j]) wall.push({i,j});
        }
    }

    vis[0][0] = 1;
    q.push({0,0});
    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        for(int i=0;i<4;i++){
            int x = cur.first + dx[i];
            int y = cur.second + dy[i];
            if(x<0||x>=n||y<0||y>=m) continue;
            if(vis[x][y]!=0) continue;
            if(board[x][y]){
                if(vis_copy[x][y]==0) vis_copy[x][y] = vis[cur.first][cur.second] + 1;
                else if(vis_copy[x][y]>vis[cur.first][cur.second]) vis_copy[x][y] = vis[cur.first][cur.second] + 1;
            }
            else{
                vis[x][y] = vis[cur.first][cur.second] + 1;
                q.push({x,y});
            }
        }
    }

    int wall_s = wall.size();
    for(int i=0; i<wall_s; i++){
        pair<int,int> w = wall.front(); wall.pop();
        q.push(w);
        while(!q.empty()){
            pair<int,int> cur = q.front(); q.pop();
            if(vis_copy[cur.first][cur.second]==0) continue;
            for(int j=0;j<4;j++){
                int x = cur.first + dx[j];
                int y = cur.second + dy[j];
                if(x<0||x>=n||y<0||y>=m) continue;
                if(board[x][y]) continue;
                int copy = vis_copy[x][y];
                int origin = vis_copy[cur.first][cur.second] + 1;
                if(copy==0){
                    vis_copy[x][y] = origin;
                    q.push({x,y});
                }
                else if(copy>origin){
                    vis_copy[x][y] = origin;
                    q.push({x,y});
                }
            }
        }
    }

    int copy = vis_copy[n-1][m-1];
    int origin = vis[n-1][m-1];
    
    if(origin==0&&copy!=0){
        cout<<copy;
    }
    else if(origin!=0&&copy==0){
        cout<<origin;
    }
    else if(origin==0&&copy==0){
        cout<<-1;
    }
    else if(origin!=0&&copy!=0){
        if(copy<origin) cout<<copy;
        else cout<<origin;
    }
}