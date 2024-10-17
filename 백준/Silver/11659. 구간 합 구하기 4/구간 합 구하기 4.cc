#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long table[100001]; //앞에서부터 현재 값을 더해나가는 값
long long number[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>number[i];
	}
	table[1] = number[1];
	for(int i=1;i<=n;i++){
		table[i] = table[i-1] + number[i];
	}
	int n1,n2;
	for(int i=0;i<m;i++){
		cin>>n1>>n2;
		if(n1==1){
			cout<<table[n2]<<"\n";
		}
		else{
			cout<<table[n2]-table[n1-1]<<"\n";
		}
	}

}