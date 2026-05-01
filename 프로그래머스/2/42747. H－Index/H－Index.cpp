#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 0 1 2 7 10
// h = 10 -> 0까지 돌면서 
// ⭐️ upper_bound: 찾는 값 초과인 첫 번째 위치
// ⭐️ lower_bound: 찾는 값 이상인 첫 번째 위치

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end());
    int end_index = citations.size();
    for(int i=citations[end_index-1]; i>=0; i--){
        if((citations.end() - lower_bound(citations.begin(), citations.end(), i)) >= i) return i;
    }
    return 0;
}