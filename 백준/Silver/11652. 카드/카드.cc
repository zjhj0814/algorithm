#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long n;
	long long tmp;
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	long long max_count = 1; long long number = v[0]; //
	long long recent_count = 0; long long recent = v[0]; //
	for(long long i=0;i<n;i++){
		if(recent_count>max_count){
			max_count = recent_count;
			number = recent;
		}
		if(v[i]==recent){
			recent_count++;
		}
		else{
			recent = v[i];
			recent_count = 1;
		}
	}
	if(recent_count>max_count){
		max_count = recent_count;
		number = recent;
	}
	cout<<number;
}