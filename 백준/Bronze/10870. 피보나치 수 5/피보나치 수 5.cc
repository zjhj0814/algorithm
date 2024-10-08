#include <iostream>
#include <vector>
using namespace std;

int recursive(int n){
    if(n>=2) return recursive(n-1) + recursive(n-2);
    else if(n==1) return 1;
    else return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin>>n;
    cout<<recursive(n);
}
