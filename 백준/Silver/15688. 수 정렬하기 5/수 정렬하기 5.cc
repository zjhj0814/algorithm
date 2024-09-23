#include <iostream>
using namespace std;

int pos[1000001];
int neg[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin>>n;
	int tmp;
	while(n--){
		cin>>tmp;
		if(tmp>=0) pos[tmp]++;
		else neg[abs(tmp)]++;
	}

	for(int i=1000000; i>0; i--){
		for(int j=0;j<neg[i];j++){
			cout<<"-"<<i<<'\n';
		}
	}
	for(int i=0;i<=1000000;i++){
		for(int j=0;j<pos[i];j++){
			cout<<i<<'\n';
		}
	}
}