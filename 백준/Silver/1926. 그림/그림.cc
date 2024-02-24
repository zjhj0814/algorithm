#include <iostream>
#include <queue>
#include <string>
using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    int** board=new int*[n];
    int** visit=new int*[n]; 
    for(int i=0; i<n; i++){
        board[i]=new int[m];
        visit[i]=new int[m]{};
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>board[i][j];
        }
    }

    queue<pair<int,int>> q;
    int count=0, max=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            //BFS 시작점 찾기
            if(visit[i][j]==1) continue; //방문한 경우 패스
            if(board[i][j]==0) continue; //그림이 아닌 경우 패스
            q.push({i,j});
            visit[i][j]=1;

            int size=0; //그림 크기 재는 것
            while(!q.empty()){
                pair<int,int> cur=q.front(); q.pop(); size++;
                for(int dir=0; dir<4; dir++){
                    int nx=cur.first+dx[dir];
                    int ny=cur.second+dy[dir];
                    if(nx<0||nx>=n||ny<0||ny>=m) continue;
                    if(visit[nx][ny]||board[nx][ny]!=1) continue;
                    visit[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
            max=(max<size)? size:max; //최대 그림 크기 선정
            count++; //그림 갯수 세기
        }
    }
    cout<<count<<'\n'<<max;

    for(int i=0; i<n; i++){
        delete[] board[i];
    }
    delete[] board;
}