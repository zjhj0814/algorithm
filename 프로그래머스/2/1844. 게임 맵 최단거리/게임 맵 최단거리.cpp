#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int solution(vector<vector<int> > maps)
{
    int n = maps.size(); int m = maps[0].size();
    int visit[n][m];
    for(int i=0;i<n;i++){
        fill(visit[i], visit[i]+m, 0);
    }
    
    queue<pair<int,int>> q;
    q.push({0,0});
    visit[0][0] = 1;
    while(!q.empty()){
        auto current = q.front(); q.pop();
        for(int i=0;i<4;i++){
            int nx = current.first + dx[i];
            int ny = current.second + dy[i];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(visit[nx][ny] || maps[nx][ny] == 0) continue;
            visit[nx][ny] = visit[current.first][current.second] + 1;
            q.push({nx,ny});
        }
    }
    if(visit[n-1][m-1] == 0) return -1;
    return visit[n-1][m-1];
}