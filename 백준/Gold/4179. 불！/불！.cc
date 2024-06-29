#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int board[1000][1000]; // 막힌 길은 다 0으로, 불길은 -1로, 갈 수 있는 길 1로
int vis[1000][1000];   // 가장 빠른 탈출시간 찾기 위해

queue<pair<int, int>> fire; // 불길
queue<pair<int, int>> q;    // 지훈이

pair<int, int> path(int R, int C)
{
    while (!q.empty())
    {
        // 내가 이동함과 동시에 옮겨지는 불길 계산하기
        int f_size = fire.size();
        for (int i = 0; i < f_size; i++)
        {
            pair<int, int> cur = fire.front(); fire.pop();
            for (int j = 0; j < 4; j++)
            {
                int x = cur.X + dx[j];
                int y = cur.Y + dy[j];
                if (x < 0 || x >= R || y < 0 || y >= C)
                    continue;
                if (board[x][y] != 1)
                    continue;
                board[x][y] = -1;
                fire.push({x, y});
            }
        }

        // 내가 이동할 수 있는 곳 파악하기
        int q_size = q.size();
        for(int i=0; i<q_size; i++){
            pair<int, int> cur = q.front(); q.pop();
            if (cur.X == 0 || cur.X == (R - 1) || cur.Y == 0 || cur.Y == (C - 1))
                return make_pair(cur.X, cur.Y);
            for (int j = 0; j < 4; j++)
            {
                int x = cur.X + dx[j];
                int y = cur.Y + dy[j];
                if (x < 0 || x >= R || y < 0 || y >= C)
                    continue;
                if (board[x][y] != 1 || vis[x][y])
                    continue; // vis가 0이 아닌 경우로 다시 가면 돌아가는 경우이니까 이 부분도 제외함

                vis[x][y] = vis[cur.X][cur.Y] + 1;
                q.push({x, y});
            }
        }
    }
    return make_pair(-1,-1); //불가능
}


int main()
{
    int R, C;
    cin >> R >> C;

    for (int i = 0; i < R; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < C; j++)
        {
            char tmp = input[j];
            switch (tmp)
            {
            case 'F':
                board[i][j] = -1;
                fire.push({i, j});
                break;
            case 'J':
                vis[i][j] = 1;
                board[i][j] = 1;
                q.push({i, j});
                break;
            case '.':
                board[i][j] = 1;
                break;
            case '#':
                break;
            }
        }
    }

    const pair<int,int> exit = path(R, C);
    if(exit.X==-1&&exit.Y==-1) cout<<"IMPOSSIBLE";
    else cout<<vis[exit.X][exit.Y];
}