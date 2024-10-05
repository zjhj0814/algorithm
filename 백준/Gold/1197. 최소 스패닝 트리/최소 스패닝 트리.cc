#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int v, e;
int cnt = 0; //선택된 '간선'의 수
int ans = 0;
bool mst[10001];
vector<pair<int,int>> graph[10001]; //비용, 도착 정점
priority_queue< pair<int,int>, 
	vector<pair<int,int>>, greater<pair<int,int>>> pq; //비용, 도착 정점

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int a,b,c;
	cin>>v>>e;
	for(int i=0;i<e;i++){
		cin>>a>>b>>c; //a->b:c
		graph[a].push_back({c,b});
		graph[b].push_back({c,a});
	}
	mst[1] = true;
	for(const pair<int,int>& nxt : graph[1]){
		pq.push({nxt.first, nxt.second});
	}
	while(cnt<v-1){
		pair<int,int> node = pq.top(); pq.pop();
		if(mst[node.second] == true) continue;
		for(const pair<int,int>& nxt : graph[node.second]){
			pq.push({nxt.first, nxt.second});
		}
		mst[node.second] = true;
		cnt++;
		ans += node.first;
	}
	cout << ans;
}