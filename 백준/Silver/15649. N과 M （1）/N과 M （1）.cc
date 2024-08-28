#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;

int arr[9]; //저장된 수
bool isused[9]; //1부터 n까지의 수가 사용됐는지
int n,m; //n 수의 범위, m 수열의 갯수

void back(int sz){
    //맨 마지막 노드 - 출력
    if(sz==m){
        for(int i=0;i<m;i++){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
    }
    //맨 마지막 노드가 아닐때 - 삽입
    else{
        int next = sz + 1;
        for(int i=1;i<=n;i++){
            if(!isused[i]){
                arr[sz] = i;
                isused[i] = true;
                back(next);
                isused[i] = false;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>m;
    fill(&isused[0],&isused[9],0);
    back(0);

}