#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

queue<int> q;
int answer = 0;

void row_based_dfs(int row, int n, vector<vector<int>>& computers, vector<int>& visit){
    for(int col=0; col<n; col++){ // 0부터 탐색
        if(computers[row][col] == 0 || visit[col] != 0) continue;
        if(row == col){
            answer++;
            visit[row] = answer;
            continue;
        }
        visit[col] = answer;
        q.push(col);
    }
}

int solution(int n, vector<vector<int>> computers) {
    vector<int> visit(n,0);
    
    for(int i=0;i<n;i++){
        if(visit[i] != 0) continue;
        answer++; // 새 네트워크 발견 시
        visit[i] = answer;
        q.push(i);
        row_based_dfs(i, n, computers, visit);
        while(!q.empty()){
            int next_row = q.front(); q.pop();
            row_based_dfs(next_row, n, computers, visit);
        }
    }
    return answer;
}

// 그래프의 몇 개의 영역이 존재하는지
// A -> B, B-> C, C->E
// 1 1 0 0 0
// 1 1 1 0 0
// 0 1 1 0 1
// 0 0 0 1 0
// 0 0 1 0 1