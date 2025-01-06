#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main(){
    int n;
    cin>>n;
    int number;
    for(int i=0;i<n;i++){
        cin>>number;
        v.push_back(number);
    }
    sort(v.begin(), v.end());
    int answer = 0;
    for(int i=0;i<n;i++){
        int weight = v[i]*(n-i);
        if(answer<weight) answer = weight;
    }
    cout<<answer;
}