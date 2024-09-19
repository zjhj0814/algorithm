#include <iostream>
using namespace std;

/*
18808번 : 스티커 붙이기
1. 스티커를 입력 받는 즉시, 함수를 호출한다.
2. board (0,0)부터 (n-n1,m-m1)까지 순회하며 board[i][j]가 0일 경우, 스티커를 붙일 수 있는지 테스트한다.
3. 만약 스티커를 붙일 수 있다면 board에 스티커를 붙이고 다시 1번으로 돌아간다.
	만약 스티커를 붙일 수 없다면 2번에서 계속해서 순회한다.
4. 순회를 한 후에도 스티커를 붙일 수 없다면 회전해야 하므로 다시 재귀를 통해서 회전시킨다.
	KEY_회전시키는 것을 어떻게 구현할까?
*/

int n, m; //notebook row,col
int row, col; //sticker row,col
int notebook[40][40];
int sticker[10][10];

void putSticker(int n1, int m1, int angle){
	int r1,c1;
	if(angle==0){
		r1 = 0;
		for(int i=n1;i<n1+row;i++){
			c1 = 0;
			for(int j=m1;j<m1+col;j++){
				if(sticker[r1][c1]==1) notebook[i][j] = sticker[r1][c1];
				c1++;
			}
			r1++;
		}
	}
	else if(angle==90){
		c1 = 0;
		for(int i=n1;i<n1+col;i++){
			r1 = row-1;
			for(int j=m1;j<m1+row;j++){
				if(sticker[r1][c1]==1) notebook[i][j] = sticker[r1][c1];
				r1--;
			}
			c1++;
		}
	}
	else if(angle==180){
		r1 = row-1;
		for(int i=n1;i<n1+row;i++){
			c1 = col-1;
			for(int j=m1;j<m1+col;j++){
				if(sticker[r1][c1]==1) notebook[i][j] = sticker[r1][c1];
				c1--;
			}
			r1--;
		}
	}
	else if(angle==270){
		c1 = col-1;
		for(int i=n1;i<n1+col;i++){
			r1 = 0;
			for(int j=m1;j<m1+row;j++){
				if(sticker[r1][c1]==1) notebook[i][j] = sticker[r1][c1];
				r1++;
			}
			c1--;
		}
	}
}

bool canSticker(int n1, int m1, int angle){
	int r1,c1;
	if(angle==0){
		r1 = 0;
		for(int i=n1;i<n1+row;i++){
			c1 = 0;
			for(int j=m1;j<m1+col;j++){
				if(notebook[i][j]==1&&sticker[r1][c1]==1){
					return false;
				}
				c1++;
			}
			r1++;
		}
	}
	else if(angle==90){
		c1 = 0;
		for(int i=n1;i<n1+col;i++){
			r1 = row-1;
			for(int j=m1;j<m1+row;j++){
				if(notebook[i][j]==1&&sticker[r1][c1]==1){
					return false;
				}
				r1--;
			}
			c1++;
		}
	}
	else if(angle==180){
		r1 = row-1;
		for(int i=n1;i<n1+row;i++){
			c1 = col-1;
			for(int j=m1;j<m1+col;j++){
				if(notebook[i][j]==1&&sticker[r1][c1]==1){
					return false;
				}
				c1--;
			}
			r1--; 
		}
	}
	else if(angle==270){
		c1 = col-1;
		for(int i=n1;i<n1+col;i++){
			r1 = 0;
			for(int j=m1;j<m1+row;j++){
				if(notebook[i][j]==1&&sticker[r1][c1]==1){
					return false;
				}
				r1++;
			}
			c1--;
		}
	}
	putSticker(n1,m1,angle);
	return true;
}

void starter(int angle){
	if(angle==360) return;
	if(angle==0||angle==180){
		for(int i=0; i<=n-row; i++){
			for(int j=0;j<=m-col;j++){
				if(canSticker(i,j,angle)) return;
			}
		}
	}
	else{
		for(int i=0; i<=n-col; i++){
			for(int j=0;j<=m-row;j++){
				if(canSticker(i,j,angle)) return;
			}
		}
	}
	starter(angle+90);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin>>n>>m;
	int k;
	cin>>k;
	while(k--){
		cin>>row>>col;
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				cin>>sticker[i][j];
			}
		}
		starter(0);
	}

	int cnt = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(notebook[i][j]==1) cnt++;
		}
	}
	cout<<cnt;
}