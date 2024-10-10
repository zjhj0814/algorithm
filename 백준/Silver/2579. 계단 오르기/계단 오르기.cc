#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int stair[301];
pair<int,int> table[301];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>stair[i];
    }
    table[1] = {stair[1],stair[1]};
    table[2] = {stair[2], stair[1]+stair[2]};
    for(int i=3;i<=n;i++){
        table[i] = {max(table[i-2].first, table[i-2].second)+stair[i],
                        table[i-1].first+stair[i]};
    }

    cout<<max(table[n].first,table[n].second);
}