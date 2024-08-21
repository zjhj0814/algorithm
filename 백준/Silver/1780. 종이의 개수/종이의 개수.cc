#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;

int paper[2187][2187];
int cnt[3]; //-1, 0, 1 -> 0, 1, 2

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
        ++cnt[++tmp];
    }
    else{
        //x좌표의 간격 = y좌표의 간격, 입력값은 3의 승수
        int paper_size = (x2-x1+1)/3;
        int end_point = paper_size - 1;

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

    cout<<cnt[0]<<'\n'<<cnt[1]<<'\n'<<cnt[2]<<'\n';
}
