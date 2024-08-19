#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;

int z(int rc, const int r, const int c){
    if(rc == 1){ //4칸만 남았을 경우
        return r*2 + c*1;
    }

    int location = (rc + 1)/2; //rc는 매번 홀수 -> location은 매번 짝수
    const int mul = location * location;

    if(r>=location&&c>=location){ //4번
        return 3*mul + z(location - 1, r-location, c-location);
    }
    else if(r<location&&c<location){ //1번
        return z(location - 1, r, c); //0*mul+z()
    }
    else if(r<location&&c>=location){ //2번
        return 1*mul + z(location - 1, r, c-location);
    }
    else{ //3번
        return 2*mul + z(location - 1, r-location, c);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, r, c;
    cin>>n>>r>>c;
    int rc = (1<<n) - 1 ; //row, column의 마지막 줄 ex. 0~2^n-1
    int ans = z(rc, r, c);
    cout<<ans;
}
