#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;

int l; // l - 문자열의 알파벳 수
int c; // c - 가능한 알파벳의 수
string com = "aeiou";
vector<char> str; //char str[16]; //문자열, 0~15 idx 사용, 0~l-1
vector<char> alphabet; //char alphabet[16]; //알파벳, 0~15 idx 사용 가능, 0~c-1

//접근 방법
//KEY_가능한 알파벳을 사전에 사전순으로 나열해야 함 + 모음, 자음 검증

void back(int alpha, int idx){ //알파벳 idx, 문자열 idx
    if(idx==l){
        string tmp;
        int aeiou = 0, others = 0;
        for(auto iter = str.begin(); iter!=str.end(); iter++){
            if(com.find(*iter)==string::npos) others++;
            else aeiou++;
            tmp+=*iter;
        }
        if(aeiou>=1&&others>=2) cout<<tmp<<'\n';
        return;
    }
    else if(alpha==c){
        return;
    }
    else{
        for(int i=alpha;i<c;i++){
            str.push_back(alphabet[i]);
            back(i+1, idx+1);
            str.pop_back();
        }
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>l>>c;
    char tmp;
    for(int i=0;i<c;i++){
        cin>>tmp;
        alphabet.push_back(tmp);
    }
    sort(alphabet.begin(), alphabet.end());
    back(0,0);
}
