#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int,int>> meeting; //{시작 시간, 끝나는 시간}

bool compare(pair<int,int>& p1, pair<int,int>& p2){
    if(p1.second!=p2.second){
        return p1.second<p2.second;
    }
    return p1.first<p2.first;
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int start, end;
        cin>>start>>end;
        meeting.push_back({start, end});
    }
    sort(meeting.begin(), meeting.end(), compare);
    int time = -1, count = 0;
    for(int i=0;i<n;i++){
        if(time<=meeting[i].first){
            count++;
            time = meeting[i].second;
        }
    }
    cout<<count;
}