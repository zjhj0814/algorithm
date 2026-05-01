#include <string>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    // 문자열 정렬(내림차순) 후 이어붙이기
    vector<string> nums;
    for(auto number : numbers){
        nums.push_back(to_string(number));
    }
    sort(nums.begin(), nums.end(), [](const string& a, const string& b){
        return a + b > b + a; //⭐️ 문자열을 이어붙인 결과가 더 큰 순으로 정렬
    });
    for(auto num: nums){
        answer += num;
    }
    if(answer[0] == '0') return "0"; // 0....0이라면 0 반환
    return answer;
}