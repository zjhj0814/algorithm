#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool dfs(string current, vector<string>& path,
         vector<vector<string>>& tickets, vector<bool>& used) {

    // 종료 조건: 모든 티켓 사용
    if(path.size() == tickets.size() + 1) return true;

    for(int i = 0; i < tickets.size(); i++) {
        if(used[i]) continue;                   // 이미 사용한 티켓
        if(tickets[i][0] != current) continue;  // 출발지 다름

        used[i] = true;
        path.push_back(tickets[i][1]);

        if(dfs(tickets[i][1], path, tickets, used)) return true;

        // 백트래킹
        used[i] = false;
        path.pop_back();
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    // 알파벳 순 정렬 → DFS에서 먼저 탐색하는 게 알파벳 앞선 경로
    sort(tickets.begin(), tickets.end());

    vector<string> path;
    vector<bool> used(tickets.size(), false);

    path.push_back("ICN");  // 시작점
    dfs("ICN", path, tickets, used);

    return path;
}