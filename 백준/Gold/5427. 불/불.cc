#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int board[1000][1000]; //갈 수 있으면 1, 벽이면 0, 불타고 있으면 -1
int vis[1000][1000]; //
//int fire[1000][1000]; //불 타는 중이면 1, 불 타지 않으면 0

void bfs(queue<pair<int,int>>& human, queue<pair<int,int>>&  fire, int w, int h){
    while(!human.empty()){ //조건을 잘 모르겠군!!!
        int sizef = fire.size(); int sizeh = human.size();
        for(int i=0; i<sizef; i++){
            pair<int,int> curf = fire.front(); fire.pop();
            for(int j=0; j<4; j++){
                int x = curf.first + dx[j];
                int y = curf.second + dy[j];
                if(x<0||x>=h||y<0||y>=w) continue;
                if(board[x][y]!=1) continue;
                board[x][y] = -1;
                fire.push({x,y});
            }
        }
        for(int i=0; i<sizeh; i++){
            pair<int,int> curh = human.front(); human.pop();
            if(curh.first==0||curh.first==(h-1)||curh.second==0||curh.second==(w-1)){
                cout<<vis[curh.first][curh.second]<<'\n';
                return;
            }
            for(int j=0; j<4; j++){
                int x = curh.first + dx[j];
                int y = curh.second + dy[j];
                if(x<0||x>=h||y<0||y>=w) continue;
                if(board[x][y]!=1||vis[x][y]!=0) continue;
                vis[x][y] = vis[curh.first][curh.second] + 1;
                human.push({x,y});
            }
        }   
    }
    cout<<"IMPOSSIBLE\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T,w,h;
    char tmp;
    cin>>T;
    while(T--){
        fill(&board[0][0],&board[999][1000],0);
        fill(&vis[0][0],&vis[999][1000],0);
        //fill(&fire[0][0],&fire[999][1000],0);

        queue<pair<int,int>> human;
        queue<pair<int,int>> fire;
        cin>>w>>h;

        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin>>tmp;
                switch(tmp){
                    case '.':
                        board[i][j] = 1;
                        break;
                    case '@':
                        board[i][j] = 1;
                        vis[i][j] = 1;
                        human.push({i,j});
                    case '#':
                        break;
                    case '*':
                        board[i][j] = -1;
                        fire.push({i,j});
                        break;
                }
            }
        }

        bfs(human, fire, w, h);

    }
}