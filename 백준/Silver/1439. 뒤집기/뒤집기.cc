#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int cnt[2];

int main(){
    string s;
    cin>>s;
    cnt[s[0]-'0']++;

    for(int i=1;i<s.size();i++){
        if(s[i-1]!=s[i]) cnt[s[i]-'0']++;
    }

    cout<<min(cnt[0],cnt[1]);
}