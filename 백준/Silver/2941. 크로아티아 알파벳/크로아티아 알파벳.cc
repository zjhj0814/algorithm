#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<string> sep = {"c=", "c-", "d-", "lj", "nj", "s="};

    string s;
    cin >> s;

    int alphabet_size = s.size();
    int pos = 0;
    // "dz="과 "z="이 겹치니까 별도 처리
    while(pos < s.size()){
        int nxt_pos = s.find("z=", pos);
        if(nxt_pos == -1) break;
        pos = nxt_pos + 2;
        if(nxt_pos > 0 && (s[nxt_pos-1] == 'd')){ //"dz="이었다면
            alphabet_size -= 2;
        }
        else alphabet_size -= 1;
    }
    for(int i=0; i<sep.size(); i++){
        pos = 0;
        while(pos < s.size()){
            int nxt_pos = s.find(sep[i], pos);
            if(nxt_pos == -1) break;
            pos = nxt_pos + sep[i].size();
            alphabet_size -= sep[i].size() - 1;
        }
    }
    cout << alphabet_size;
}