#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool cmp(pair<pair<int,int>,int>& p1, pair<pair<int,int>,int>& p2){
    if(p1.first.second!=p2.first.second){
        return p1.first.second<p2.first.second;
    }    
    return p1.first.first>p2.first.first;
}

vector<pair<pair<int,int>,int>> v;
int home[2001];

int main(){
    int n,c,m;
    cin>>n>>c>>m;
    int s,r,box;
    for(int i=0;i<m;i++){
        cin>>s>>r>>box;
        v.push_back({{s,r},box});
    }
    sort(v.begin(), v.end(), cmp);
    int answer = 0;
    for(auto it=v.begin(); it!=v.end(); it++){
        const int sender_number = it->first.first;
        const int receiver_number = it->first.second;
        const int box_number = it->second;

        int available = box_number;
        for(int i=sender_number; i<receiver_number; i++){
            if(home[i]+box_number>=c){
                if(c-home[i]<available) available = c-home[i];
            }
        }
        if(available==0) continue;
        for(int i=sender_number; i<receiver_number; i++){
            home[i] += available;
        }
        answer += available;
    }
    cout<<answer;
}