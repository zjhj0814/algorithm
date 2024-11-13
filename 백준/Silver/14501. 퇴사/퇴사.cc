#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int schedule[17];
int points[17];
int table[17];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>schedule[i]>>points[i];
    }

    for(int i=n;i>=1;i--){
        int deadline = i+schedule[i];
        if(deadline>n+1){
            table[i] = table[i+1];
        }
        else{
            table[i] = max(table[i+1], table[deadline] + points[i]);
        }
    }

    cout<<table[1];
}