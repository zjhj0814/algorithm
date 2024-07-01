#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int dx[]={-1,1,2};

int vis[200001];

int main(){
    int N,K;
    cin>>N>>K;
    queue<int> q;
    int diff = abs(K-N);
    if(diff==0){
        cout<<0;
        return 0;
    }

    vis[N] = 1;
    q.push(N);
    int x;

    while(!q.empty()){
        int cur = q.front(); q.pop();
        //cout<<endl<<cur<<"->";
        for(int i=0; i<3; i++){
            if(i==2) x = cur * dx[i];
            else x = cur + dx[i];

            if(x<0||x>=200000) continue;
            if(vis[x]!=0) continue;
            vis[x] = vis[cur] + 1;
            if(x==K){
                cout<<vis[x]-1;
                return 0;
            }
            //cout<<x<<' ';
            q.push(x);
        }
    }
}