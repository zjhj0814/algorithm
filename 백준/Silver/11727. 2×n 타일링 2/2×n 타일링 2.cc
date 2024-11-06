#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int table[1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    //1 - 1
    //2 - 3 +2
    //3 - 5 +1
    //4 - 11 +2

    //5 - 21 +1
    //6 - 43 +2
    //7 - 85 +1

    //8 - 171 +2

    int n;
    cin>>n;

    table[1] = 1;

    for(int i=2;i<=n;i++){
        if(i%2==0){
            table[i] = (table[i-1]*2 + 1)%10007;
        }
        else{
            table[i] = (table[i-1]*2 -1)%10007;
        }
    }
    
    cout<<table[n];

}
