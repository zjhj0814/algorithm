#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;

char board[3072][6143];

void recursive(int i,int j,int n){
    if(n==3){
        //첫번째 줄
        board[i][j] = '*';
        //두번째 줄
        board[i+1][j-1] = '*';
        board[i+1][j+1] = '*';
        //세번째 줄
        for(int tmp=-2;tmp<=2;tmp++){
            board[i+2][j+tmp] = '*';
        }
    }
    else{
        int const new_n = n/2;
        //cout<<i<<' '<<j<<' '<<new_n<<'\n';
        //도착한 꼭짓점에 가장 작은 삼각형을 그리자
        recursive(i,j,new_n);
        //새로운 꼭짓점을 찾아서 이동하자
        recursive(i+new_n,j-new_n,new_n);
        recursive(i+new_n,j+new_n,new_n);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin>>n;
    fill(&board[0][0],&board[3071][6143],' ');
    recursive(0,n-1,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<(2*n-1);j++){
            cout<<board[i][j];       
        }
        cout<<'\n';
    }
}