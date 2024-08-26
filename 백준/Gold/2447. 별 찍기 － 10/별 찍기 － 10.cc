#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;

void recursive(int i,int j,int n){
    if(n==1){
        cout<<'*';
    }
    else if((i/(n/3))%3==1&&(j/(n/3))%3==1){ //blank
        cout<<' ';
    }
    else{
        recursive(i,j,n/3);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            recursive(i,j,n);
        }
        cout<<'\n';
    }

}

//3 - (1,1),(1,4),(1,7)...(4,1),(4,4)... -> (i%3==1,j%3==1)
//9 - (3,3),(3,4),(3,5),(4,3),(4,4)...(3,12) -> 3,4,5,12,13,14 -> ((i/3)%3==1,(j/3)%3==1)
//27 - (9,9),(9,10),...,(10,9),(10,10)...