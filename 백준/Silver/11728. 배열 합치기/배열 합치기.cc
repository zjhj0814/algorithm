#include <iostream>
using namespace std;

int n,m;
int arr[2000000];
int arr1[1000000];
int arr2[1000000];

void mergesort(){
	//idx1, idx2
	//idx1과 idx2 비교
	//더 작은 값 arr에 삽입, 해당 인덱스+1
	int idx1 =0, idx2=0, idx=0;
	while(idx1!=n&&idx2!=m){
		if(arr1[idx1]<arr2[idx2]){
			arr[idx] = arr1[idx1];
			idx1++;
		}
		else{
			arr[idx] = arr2[idx2];
			idx2++;
		}
		idx++;
	}
	if(idx1==n){ //arr에 arr[idx2]부터 arr[m-1]까지 채우기
		for(int i=idx2;i<m;i++){
			arr[idx] = arr2[i];
			idx++;
		}
	}
	else if(idx2==m){ //arr에 arr[idx1]부터 arr[n-1]까지 채우기
		for(int i=idx1;i<n;i++){
			arr[idx] = arr1[i];
			idx++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>arr1[i];
	}	
	for(int i=0;i<m;i++){
		cin>>arr2[i];
	}
	mergesort();
	for(int i=0;i<(n+m);i++){
		cout<<arr[i]<<' ';
	}
}