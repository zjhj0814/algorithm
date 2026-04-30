#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>

using namespace std;

int answer = 51;
unordered_set<string> visit;
queue<pair<string,int>> q; // (바꾼 단어, 바꾼 횟수)

void word_dfs(string& target, int size, vector<string>& words){
    string temp_string = q.front().first; 
    int temp_count = q.front().second;
    q.pop();
    visit.insert(temp_string); //사이클 생기지 않도록 삭제
    if(target.compare(temp_string) == 0 ){
        answer = min(answer, temp_count);
        return; // 만약 target이면 바꾼 횟수를 업데이트하고 끝   
    }
    for(int i=0;i<size;i++){ // 단어의 인덱스별로 바꿀 수 있는지 확인하고 바꿈
        for(auto word: words){
            if(visit.find(word) != visit.end()) continue;
            if(temp_string.substr(0,i).compare(word.substr(0,i)) == 0 
                && temp_string.substr(i+1).compare(word.substr(i+1)) == 0){
                q.push({word, temp_count+1});
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    q.push({begin,0});
    int size = begin.size();
    while(!q.empty()){
        word_dfs(target, size, words);
    }
    if(answer == 51) return 0; //만약 변환할 수 없다면
    return answer;
}

// begin.size()에 따라 각 글자를 바꾸는 여러가지 경우의 수를 구한다. 이때 그 횟수를 저장한다. BFS
// 한 번 바꾼 words는 루프처럼 다시 되돌아가므로 한 번 바꾼 words로 되돌아가지 않는다.