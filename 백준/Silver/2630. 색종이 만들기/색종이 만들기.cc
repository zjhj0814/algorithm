#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;

int paper[128][128];
int cnt[2]{}; //0,1 -> 하얀색, 파란색 종이의 수

void recursive(int x1, int x2, int y1, int y2){
    bool flag = true;
    int tmp = paper[x1][y1];
    for(int i=x1;i<x2;i++){
        for(int j=y1;j<y2;j++){
            if(tmp!=paper[i][j]){
                flag = false;
                break;
            }
        }
    }
    if(flag){
        if(tmp==1||tmp==0) cnt[tmp]++;
    }
    else{
        int paper_size = (x2-x1)/2;
        for(int i=x1;i<x2;i+=paper_size){
            for(int j=y1;j<y2;j+=paper_size){
                recursive(i, i+paper_size, j, j+paper_size);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>paper[i][j];
        }
    }

    recursive(0,n,0,n); //x1,y1 이상 ~ x2,y2 미만 탐색

    cout<<cnt[0]<<'\n'<<cnt[1]<<'\n';
}
