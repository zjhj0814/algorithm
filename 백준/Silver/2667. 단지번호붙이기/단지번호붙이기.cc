#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

int n;
int board[25][25];
priority_queue<int,vector<int>,greater<int>> block; //{단지내 집의 수, 단지 번호}
int cnt = 0;

int BFS(int nx, int ny, int number){
    queue<pair<int,int>> q; int tmp = 0;
    q.push({nx,ny}); board[nx][ny] = number; tmp++;

    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        for(int i=0;i<4;i++){
            int x = cur.first+dx[i];
            int y = cur.second+dy[i];
            if(x<0||x>=n||y<0||y>=n) continue;
            if(board[x][y]!=1) continue;
            q.push({x,y}); board[x][y] = number; tmp++;
        }
    }
    return tmp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string str;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>str;
        for(int j=0;j<n;j++){
            board[i][j] = str[j]-'0';
        }
    }
    int number = 2;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j] == 1){
                block.push({BFS(i, j, number)});
                number++; cnt++;
            }
        }
    }
    cout<<cnt<<'\n';
    while(!block.empty()){
        cout<<block.top()<<'\n';
        block.pop();
    }
}