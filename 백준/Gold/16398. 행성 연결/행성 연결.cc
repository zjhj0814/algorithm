#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
long long ans = 0, cnt = 0;
bool mst[1001];
vector<pair<int,int>> graph[1001];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin>>n;
	int cost;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>cost;
			if(i==j) continue;
			graph[i].push_back({cost,j});
		}
	}
	mst[1] = true;
	for(auto nxt : graph[1]){
		pq.push({nxt.first, nxt.second});	
	}
	while(cnt<n-1){
		auto node = pq.top(); pq.pop();
		if(mst[node.second]==true) continue;
		mst[node.second] = true;
		for(auto nxt : graph[node.second]){
			pq.push({nxt.first, nxt.second});
		}
		cnt++; ans += node.first;
	}
	cout<<ans;
}