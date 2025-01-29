#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int>> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    sort(v.begin(), v.end());
    int answer = 0;
    int location = -1000000000;
    int i = 0;
    while(i<n){
        if(v[i].first<=location){
            int start = v[i].first;
            int end = v[i].second;
            while(i<n && v[i].first<=end){
                if(v[i].second>=end) end = v[i].second;
                i++;
            }
            answer += end - start;
            location = end;
        }
        else{
            location = v[i].first;
        }
    }
    cout<<answer;
}