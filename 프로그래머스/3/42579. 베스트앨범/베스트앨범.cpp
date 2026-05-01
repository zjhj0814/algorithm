#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    // (장르, 재생 횟수 합)
    unordered_map<string,int> m;
    // (장르, 가장 많이 재생한 곡 2곡의 번호)
    unordered_map<string, pair<int,int>> um;
    for(int i=0;i<genres.size();i++){
        string& genre = genres[i];
        m[genre] += plays[i];
        
        auto iter = um.find(genre);
        if(iter == um.end()){ // 장르의 가장 첫 곡 삽입
            um.insert({genre, {i,-1}});
        } else if(iter->second.second == -1){ // 한 곡만 삽입되어 있다면
            if(plays[iter->second.first]>=plays[i]) // ⭐️ 장르 내에서 재생횟수가 같은 노래는 고유번호가 낮은 노래를 먼저 수록
                iter->second.second = i;
            else{
                iter->second.second = iter->second.first;
                iter->second.first = i;
            }
        } else { // 두 곡 다 삽입되어 있다면
            if(plays[iter->second.second]>=plays[i]) continue;
            else if(plays[iter->second.first]>=plays[i])
                iter->second.second = i;
            else{
                iter->second.second = iter->second.first;
                iter->second.first = i;
            }
        }   
    }
    
    // ⭐️ 재생횟수 합 기준 내림차순 정렬
    vector<pair<string,int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), [](const pair<string,int>& a, const pair<string,int>& b){
        return a.second > b.second;
    });
    
    vector<int> answer;
    for(pair<string,int>& genre: v){
        pair<int,int>& play_num = um[genre.first];
        answer.push_back(play_num.first);
        if(play_num.second != -1) answer.push_back(play_num.second);
    }
    return answer;
}