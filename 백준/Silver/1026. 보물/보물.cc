#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a;
    vector<int> b;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        a.push_back(temp);
    }
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        b.push_back(temp);
    }
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end());
    int answer = 0;
    for(int i=0;i<n;i++){
        int temp = a[i]*b[i];
        answer += temp;
    }
    cout<<answer;
}