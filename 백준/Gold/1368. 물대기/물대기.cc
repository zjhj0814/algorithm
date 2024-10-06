#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
int cnt = 0, ans = 0;
bool mst[301];
vector<pair<int,int>> graph[301];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int cost;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>cost;
		graph[0].push_back({cost,i});
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>cost;
			if(i==j) continue;
			graph[i].push_back({cost, j});
		}
	}
	mst[0] = true;
	for(auto nxt : graph[0]){
		pq.push({nxt.first, nxt.second});
	}
	while(cnt<n){
		auto node = pq.top(); pq.pop();
		if(mst[node.second]==true) continue;
		mst[node.second] = true;
		cnt++; ans += node.first;
		for(auto nxt : graph[node.second]){
			pq.push({nxt.first, nxt.second});
		}
	}
	cout<<ans;
}