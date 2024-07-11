#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    unsigned int K, N, temp;
    scanf("%u %u",&K, &N);
    vector<unsigned int> v; //자동으로 오름차순 정렬
    for(unsigned int i=0; i<K; i++){
        scanf("%u",&temp);
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    unsigned int left=1, right=v[K-1]; //min은 최소 갯수를 넘은 길이, max는 최소 갯수를 넘지 못한 길이-1
    unsigned int count=0, med; //랜선의 최대 길이를 찾기 위해서 이분탐색 진행
    unsigned int res=0;
    while(left<=right){
        count=0;
        med=(left+right)/2;
        for(long long i=0; i<K; i++){
            count+=v[i]/med;
        }
        if(count>=N){
            left=med+1;
            res=max(res,med);
        }
        else{
            right=med-1;
        }
    }
    printf("%u",res);
}