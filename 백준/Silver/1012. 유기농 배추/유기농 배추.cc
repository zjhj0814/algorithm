#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

queue<pair<int, int>> q;
int board[50][50];
int vis[50][50];
int N,M;

void bfs(int N,int M)
{
    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = cur.first + dx[i];
            int y = cur.second + dy[i];
            if (x < 0 || x >= N || y < 0 || y >= M)
                continue;
            if (vis[x][y] || board[x][y] == 0)
                continue;
            vis[x][y] = 1;
            q.push({x,y});
        }
    }
}

int main()
{
    int T;
    int N,M, K;
    int tmp1, tmp2;
    cin >> T;

    while (T--)
    {
        cin >> M >> N >> K; // M은 열의 수, N은 행의 수
        int count = 0;
        for (int i = 0; i < K; i++)
        {
            cin >> tmp1 >> tmp2;
            board[tmp2][tmp1] = 1;
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (board[i][j]&&vis[i][j] == 0){
                    q.push({i,j});
                    bfs(N,M);
                    count++;
                    //cout<<i<<' '<<j<<'\n';
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            fill(board[i], board[i] + M, 0);
            fill(vis[i], vis[i] + M, 0);
        }
        cout << count << endl;
    }
}