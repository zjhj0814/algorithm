#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;

long long a;
long long c;

long long mod(long long b){
    if(b==1) return (a%c); //base condition

    if(b%2!=0) return (mod(b-1)*(a%c))%c; //홀수일때
    else{ //짝수일때
        long long temp = mod(b/2);
        return (temp*temp)%c;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long b;
    cin>>a>>b>>c;
    cout<<mod(b)<<endl;
}
