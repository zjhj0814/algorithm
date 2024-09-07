#include <iostream>
#include <set>
#include <algorithm>
#include <stack>
using namespace std;

char board[25];
int vis[5][5];
set<int> s;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int cnt = 0;

bool adjacent(){
    //1차원 배열 -> 2차원 배열로 전환(set의 값은 1로 초기화) 후,
    //DFS를 통해 s.begin()의 위치부터 DFS를 실행 후, vis이 1이면 방문한 값을 -1로 초기화
    //이때 아직도 vis이 1인 값이 있으면 인접하지 않은 노드이므로 false 반환
    //1인 값이 존재하지 않다면 true 반환
    fill(&vis[0][0], &vis[4][5],0);
    for(auto iter = s.begin(); iter!=s.end(); iter++){
        vis[*iter/5][*iter%5] = 1;
    }
    int root_x = *s.begin()/5;
    int root_y = *s.begin()%5;
    stack<pair<int,int>> sta;
    sta.push({root_x,root_y});
    vis[root_x][root_y] = -1;

    while(!sta.empty()){
        pair<int,int> cur = sta.top(); sta.pop();
        for(int dir=0;dir<4;dir++){
            int x = cur.first + dx[dir];
            int y = cur.second + dy[dir];
            if(x<0||x>=5||y<0||y>=5) continue;
            if(vis[x][y]!=1) continue;
            vis[x][y] = -1;
            sta.push({x,y});
        }
    }
    
    for(auto iter = s.begin(); iter!=s.end(); iter++){
        if(vis[*iter/5][*iter%5]!=-1) return false;
    }
    return true;
}

bool valid_check(){
    //board에서 이다솜파가 4명 이상인지 체크
    int s_count = 0;
    for(auto iter = s.begin(); iter!=s.end(); iter++){
        if(board[*iter]=='S') s_count++;
    }
    return (s_count>=4);    
}

void combination(int next, int sz){ 
    //next부터 그 다음것까지 사이즈가 7인 조합을 만드는 함수
    //next : next 포함 ~ 끝까지 원소 사용 가능
    //sz : 현재까지의 조합 원소 사이즈
    if(sz==7){
        if(valid_check()&&adjacent()){
            cnt++;
        }
        return;
    }
    else{
        for(int i=next;i<25;i++){
            s.insert(i);
            combination(i+1, sz+1);
            s.erase(i);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string line;
    for(int i=0;i<5;i++){
        cin>>line;
        for(int j=0;j<5;j++){
            board[i*5+j] = line[j];
        }
    }
    combination(0,0);
    cout<<cnt;
}

//문제해결기법
//1. 먼저, 필요한 알고리즘, 자료구조를 설정하면서 문제 해결 방법을 탐구한다.
//2. 하나의 함수로 해결하려 하지 말고, 복잡하다면 여러 개의 함수로 분리한다.(이때 함수 역할을 잘 정리할 것)
//3. 함수에 필요한 매개변수가 무엇인지 정확하게 알고 있는다.('지금까지의' 사이즈 등등)