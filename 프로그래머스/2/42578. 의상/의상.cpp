#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> m;
    for(auto cloth: clothes){
        m[cloth[1]]++; // 같은 이름을 가진 의상 존재 X
    }
    int answer = 1;
    for(auto iter = m.begin(); iter!=m.end(); iter++){
        answer *= (iter->second+1);
    }
    return answer - 1;
}

// 3 * 2 - 1(전부 다 입지 않는 경우의 수)
// 4 - 1(전부 다 입지 않는 경우의 수)