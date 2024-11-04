#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int triangle[501][501];
int table[501][501]; //해당 좌표까지 오는 데 최댓값

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>triangle[i][j]; //모든 층은 1부터
		}
	}

	table[1][1] = triangle[1][1];
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(j==1) table[i][j] = table[i-1][j] + triangle[i][j];
			else if(j==i) table[i][j] = table[i-1][j-1] + triangle[i][j];
			else table[i][j] = max(table[i-1][j-1], table[i-1][j]) + triangle[i][j];
		}
	}
	
	int ans = 0;
	for(int i=1;i<=n;i++){
		if(table[n][i]>ans) ans = table[n][i];
	}	
	cout<<ans;
}