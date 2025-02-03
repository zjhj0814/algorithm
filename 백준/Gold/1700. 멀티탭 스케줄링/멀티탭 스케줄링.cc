#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

vector<int> v;
unordered_set<int> s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,k;
    cin>>n>>k;
    int temp;
    for(int i=0;i<k;i++){
        cin>>temp;
        v.push_back(temp);
    }

    int answer = 0;
    for(auto iter=v.begin();iter!=v.end();iter++){
        if(s.find(*iter)==s.end()){
            if(s.size()<n){
                s.insert(*iter);
            }
            else{
                int last_value, last_index = 0;
                for(auto it=s.begin(); it!=s.end(); it++){
                    auto i = find(iter+1, v.end(), *it);
                    int index = i-v.begin();
                    if(index==k){
                        last_value = *it;
                        break;
                    }
                    else if(index>last_index){
                        last_index = index;
                        last_value = *it;
                    }
                }
                s.erase(last_value); answer++;
                s.insert(*iter);
            }
        }
    }

    cout<<answer;
}