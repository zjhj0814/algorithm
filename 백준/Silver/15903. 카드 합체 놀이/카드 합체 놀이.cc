#include <iostream>
#include <queue>
using namespace std;

priority_queue<long long, vector<long long>, greater<long long>> pq;

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        pq.push(temp);
    }
    for(int i=0;i<m;i++){
        long long temp1 = pq.top(); pq.pop();
        long long temp2 = pq.top(); pq.pop();
        temp1 += temp2;
        pq.push(temp1); pq.push(temp1);
    }
    long long answer = 0;
    while(!pq.empty()){
        answer += pq.top(); pq.pop();
    }
    cout<<answer;
}