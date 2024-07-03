#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

char board[100][100];
int vis1[100][100];
int vis2[100][100];
queue<pair<int,int>> q1;
queue<pair<int,int>> q2;
int N;
int count1 = 0, count2 = 0;

void bfs1(const char color){ //적록색약이 아닌 사람
    while(!q1.empty()){
        pair<int,int> cur = q1.front(); q1.pop();
        for(int i=0; i<4; i++){
            int x = cur.first + dx[i];
            int y = cur.second + dy[i];
            if(x<0||x>=N||y<0||y>=N) continue;
            if(vis1[x][y]||board[x][y]!=color) continue;
            vis1[x][y] = 1;
            q1.push({x,y});
        }
    }
}

void bfs2(const char color){ //적록색약인 사람
    while(!q2.empty()){
        pair<int,int> cur = q2.front(); q2.pop();
        for(int i=0; i<4; i++){
            int x = cur.first + dx[i];
            int y = cur.second + dy[i];
            if(x<0||x>=N||y<0||y>=N) continue;
            if(vis2[x][y]) continue;
            if(color!='B'){
                if(board[x][y]=='B') continue;
            }
            else{
                if(board[x][y]!=color) continue;
            }
            vis2[x][y] = 1;
            q2.push({x,y});
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    char tmp;
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>board[i][j];
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(vis1[i][j]==0){
                count1++;
                q1.push({i,j});
                bfs1(board[i][j]);
            }
            if(vis2[i][j]==0){
                count2++;
                q2.push({i,j});
                bfs2(board[i][j]);
            }
        }
    }
    cout<<count1<<' '<<count2;
}