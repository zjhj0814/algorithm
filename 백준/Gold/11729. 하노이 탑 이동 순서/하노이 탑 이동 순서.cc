#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;

void hanoi(int n, int from, int bypass, int to){
    if(n == 1){
        cout<<from<<' '<<to<<'\n';
        return;
    }
    hanoi(n-1, from, to, bypass); //n-1개의 원판을 from -> to -> bypass
    cout<<from<<' '<<to<<'\n'; //1개의 원판을 from -> to로 이동(마지막 판)
    hanoi(n-1,bypass, from, to); //n-1개의 원판을 bypass -> from -> to
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin>>n;
    cout<<(1<<n)-1<<'\n';
    hanoi(n,1,2,3);
}
