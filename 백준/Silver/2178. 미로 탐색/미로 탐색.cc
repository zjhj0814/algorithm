#include <iostream>
#include <queue>
#include <string>
using namespace std;

#define X first
#define Y second

int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    int** board=new int*[n];
    for(int i=0; i<n; i++){
        board[i]=new int[m];
    }

    for(int i=0; i<n; i++){
        string temp;
        cin>>temp;
        for(int j=0; j<m; j++){
            board[i][j] = temp[j]-'0';
        }
    }

    queue<pair<int,int>> q;
    int vis[100][100]{};
    vis[0][0] = 1;
    q.push({0,0});

    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        for(int i=0; i<4; i++){
            int x = cur.X + dx[i];
            int y = cur.Y + dy[i];
            if(x<0||x>=n||y<0||y>=m) continue;
            if(vis[x][y]||board[x][y]!=1) continue;
            vis[x][y]=vis[cur.X][cur.Y]+1;
            q.push({x,y});
        }
    }

    cout<<vis[n-1][m-1];

    for(int i=0; i<n; i++){
        delete[] board[i];
    }
    delete[] board;
}