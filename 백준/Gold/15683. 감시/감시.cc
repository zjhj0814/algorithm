#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

//접근 방법 1 : cctv 유형 내림차순으로 optimal()로 가장 감시 영역이 많은 방향으로 결정 -> 반복
//-> 단순히 내림차순으로 결정하면, 더 낮은 cctv 유형의 결과와 합쳐서 최소의 사각지대 영역의 수를 구할 수 없음
//접근 방법 2 : cctv의 개수만큼 방향을 순열로 결정하고 이 조합을 board 영역에 표시한 후, cnt의 최솟값을 구해나가기

vector<pair<int,pair<int,int>>> cctv; //0~cctv갯수-1
vector<pair<int,int>> wall;
int n,m, answer = 64;
int board[8][8];
int direction[8];
int dx[4] = {-1,1,0,0}; //상하좌우
int dy[4] = {0,0,-1,1}; //상하좌우
pair<int,int> direction2[2] = {{0,1},{2,3}}; //상하, 좌우 0,1
pair<int,int> direction3[4] = {{0,3},{1,3},{1,2},{0,2}}; //상우, 하우, 하좌, 상좌 0,1,2,3


void draw(int x, int y, int dir){
    int curX = x, curY = y;
    while(true){
        curX += dx[dir]; curY += dy[dir];
        if(curX<0||curX>=n||curY<0||curY>=m) break;
        if((board[curX][curY]>=1&&board[curX][curY]<=5)) continue;
        if(board[curX][curY]==6) break;
        board[curX][curY] = '#';
    }
}

void combination(int next, int sz){
    if(sz == cctv.size()){
        for(int i=0;i<cctv.size();i++){ //i cctv 인덱스
            int type = cctv[i].first; int dir = direction[i];
            int x = cctv[i].second.first, y = cctv[i].second.second;
            if(type==5){
                for(int j=0;j<4;j++){ //j 방향 인덱스
                    draw(x,y,j);
                }
            }
            else if(type==4){
                for(int j=0;j<4;j++){
                    if(dir==j) continue;
                    draw(x,y,j);
                }
            }
            else if(type==3){
                int dir1 = direction3[dir].first, dir2 = direction3[dir].second;
                draw(x,y,dir1);
                draw(x,y,dir2);
            }
            else if(type==2){
                int dir1 = direction2[dir].first, dir2 = direction2[dir].second;
                draw(x,y,dir1);
                draw(x,y,dir2);
            }
            else{
                draw(x,y,dir);
            }
        }

        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==0) count++;
            }
        }

        if(answer>count){
            /*
            cout<<count<<endl;

            for(int i=0;i<cctv.size();i++){
                cout<<direction[i]<<' ';
            }
            cout<<endl;

            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    cout<<board[i][j]<<' ';
                }
                cout<<endl;
            }
            cout<<endl;
            */
            answer = count;
        }

        fill(&board[0][0],&board[7][8],0);
        for(int i=0;i<cctv.size();i++){
            board[cctv[i].second.first][cctv[i].second.second] = cctv[i].first;
        }
        for(int i=0;i<wall.size();i++){
            board[wall[i].first][wall[i].second] = 6;
        }
    }
    else{
        if(cctv[next].first==5){
            direction[next] = 0;
            combination(next+1, sz+1);
        }
        else if(cctv[next].first==2){
            for(int i=0;i<2;i++){
                direction[next] = i;
                combination(next+1,sz+1);
            }
        }
        else{
            for(int i=0;i<4;i++){
                direction[next] = i;
                combination(next+1,sz+1);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
            if(board[i][j]>=1&&board[i][j]<=5) cctv.push_back({board[i][j], {i,j}});
            else if(board[i][j]==6) wall.push_back({i,j});
        }
    }
    combination(0,0);
    cout<<answer;
}
