#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    int answer = 0;
    for(int i=n-1;i>=1;i--){
        if(v[i-1]>=v[i]){
            answer += v[i-1]-(v[i]-1);
            v[i-1] = v[i]-1;
        }
    }
    cout<<answer;
}