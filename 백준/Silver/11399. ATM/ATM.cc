#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> time;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin>>n;
    int tmp;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        time.push_back(tmp);
    }
    sort(time.begin(), time.end());
    for(int i=1;i<n;i++){
        time[i] += time[i-1];
    }
    int sum = 0;
    for(auto iter=time.begin(); iter!=time.end(); iter++){
        sum+=*iter;
    }
    cout<<sum;
}