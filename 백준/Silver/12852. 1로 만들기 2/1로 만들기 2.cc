#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int table[1000001][3];
//3으로 나눌 때, 2로 나눌 때, 1을 뺄 때 연산 최솟값

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	fill(&table[0][0],&table[1000001][2],1e9+10); //1이 될 수 없을 때 -1
	int n;
	cin>>n;
	//1
	table[1][0] = table[1][1] = table[1][2] = 0;
	//2
	table[2][1] = table[2][2] = 1;
	//3
	table[3][0] = 1, table[3][2] = min(table[2][0], min(table[2][1],table[2][2])) + 1;

	for(int i=4;i<=n; i++){
		if(i%3==0){
			table[i][0] = min(table[i/3][0], min(table[i/3][1], table[i/3][2])) + 1;
		}
		if(i%2==0){
			table[i][1] = min(table[i/2][0], min(table[i/2][1], table[i/2][2])) + 1;
		}
		table[i][2] = min(table[i-1][0], min(table[i-1][1], table[i-1][2])) + 1;
	}

	cout<<min(table[n][0], min(table[n][1], table[n][2]))<<'\n';
	int ans = n;
	while(ans>=1){
		cout<<ans<<' ';
		if(table[ans][0]<table[ans][1]&&table[ans][0]<table[ans][2]) ans/=3;
		else if(table[ans][1]<table[ans][2]) ans/=2;
		else ans-=1;
	}
}