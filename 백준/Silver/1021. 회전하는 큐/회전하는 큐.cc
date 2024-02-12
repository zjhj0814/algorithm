#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    deque<int> d;
    int N,M, idx, count=0;
    cin>>N>>M;
    for(int i=1; i<=N; i++){
        d.push_back(i);
    }
    for(int i=1; i<=M; i++){
        cin>>idx;
        int temp=0;
        while(d.front()!=idx){
            d.push_back(d.front());
            d.pop_front();
            temp++;
        }
        d.pop_front();
        count+=std::min(temp,static_cast<int>(d.size())-temp+1);
    }
    cout<<count;
}