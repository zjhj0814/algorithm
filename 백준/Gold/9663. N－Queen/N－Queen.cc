#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;

int board[16];
int cnt = 0;
int n;

void back(int row, int sz){ //열을 결정해야 할 행, 지금까지 삽입한 퀸의 사이즈
    if(sz==n){
        cnt++;
        return;
    }
    else{
        for(int i=1;i<=n;i++){ //열
            //매개변수로 받은 row행에 대한 i열에 대한 검증
            bool flag = true;
            for(int j=1;j<row;j++){ //지금까지 결정된 행
                if(board[j]==i||abs(j-row)==abs(board[j]-i)){
                    flag = false;
                    break; //해당 열은 queen을 놓을 수 없으므로 이외 행에 대한 조사를 마침
                }
            }

            if(flag){
                board[row] = i;
                back(row+1, sz+1);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    back(1,0);
    cout<<cnt;
}

//접근 방법
//1. 첫번째 행 i열에 queen이 잇다.
//2. 두번째 행 열, 대각선 조건을 체크하고 
//3. 조건에 부합한다면 바로 세번째 행 열, 대각선 조건을 체크하고 반복...
//4. 조건에 부합하지 않는다면 바로 두번째 열 다음 조건을 탐색한다.

//KEY_지금까지의 열, 대각선 조건을 어떻게 탐색할 수 있을까?(누적)
