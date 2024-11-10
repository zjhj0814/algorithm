#include <iostream>
#include <algorithm>
using namespace std;

int number[1001];
int table[1001];
int ans = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>number[i];
    }

    table[0] = 0;
    for(int i=1;i<=n;i++){        
        int max_value = 0;
        for(int j=i;j>=1;j--){
            if(number[i]>number[j]&&max_value<table[j]){
                max_value = table[j];
            }
        }
        
        if(number[i-1]>=number[i]){ //앞 숫자보다 같거나 작으면
            table[i] = max_value + number[i];
        }else{
            table[i] = max(table[i-1], max_value) + number[i];
        }

        if(ans<table[i]) ans = table[i];
    }
    cout<<ans;
}
