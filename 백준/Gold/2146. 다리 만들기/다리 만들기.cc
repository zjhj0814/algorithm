#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int board[100][100];
int contient[100][100];
int vis[100][100];
queue<pair<int,int>> q;

int length = 100000;
int n;

void bfs(int number){
    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        int new_length = vis[cur.first][cur.second] + 1;
        for(int i=0;i<4;i++){
            int x = cur.first + dx[i];
            int y = cur.second + dy[i];
            if(x<0||x>=n||y<0||y>=n) continue;
            
            if(vis[x][y]!=-1&&vis[x][y]<=new_length) continue; //이미 갔던 곳이면 패스

            if(contient[x][y]!=0&&contient[x][y]!=number){ //새로운 대륙
                if(length>new_length){
                    length = new_length;
                    //cout<<"length: "<<length<<endl;
                }
            }
            else if(contient[x][y]==number){ //원래 대륙
                board[x][y] = 0;
                vis[x][y] = 0;
                q.push({x,y});
            }
            else{
                vis[x][y] = new_length;
                q.push({x,y});
            }
        }
    }
}

void con(int count){
    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        for(int i=0;i<4;i++){
            int x = cur.first + dx[i];
            int y = cur.second + dy[i];
            if(x<0||x>=n||y<0||y>=n) continue;
            if(board[x][y]==0||contient[x][y]==count) continue;
            contient[x][y] = count;
            q.push({x,y});
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
        }
    }

    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]&&contient[i][j]==0){
                count++;
                contient[i][j] = count;
                q.push({i,j});
                con(count);
            }
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]){
                fill(&vis[0][0],&vis[99][100],-1);
                vis[i][j] = 0; //나 방문하긴 했는데 여긴 육지야
                board[i][j] = 0; //앞으로 여기는 체크 안 할거야
                q.push({i,j});
                bfs(contient[i][j]);
            }
        }
    }
    cout<<length-1;
}
