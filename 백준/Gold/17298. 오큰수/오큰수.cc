#include <iostream>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, temp;
    cin>>N;
    stack<pair<int,int>> s; //idx, 입력값
    map<int, int> NGE; //idx, NGE값
    for(int i=1; i<=N; i++){
        cin>>temp;
        while(!s.empty()&&s.top().second<temp){
            NGE.emplace(s.top().first,temp); //i번째의 NGE 값(temp)=value
            s.pop(); // 내 앞에 낮거나 같은 애들은 pop
        }
        s.emplace(i,temp);
    }
    //스택에는 이제 NGE값이 존재하지 않는 stack 값들을 -1로
    while(!s.empty()){
        NGE.emplace(s.top().first,-1);
        s.pop();
    }
    //sort(NGE.begin(), NGE.end()); map은 기본적으로 key값으로 정렬됨
    for(auto it=NGE.begin(); it!=NGE.end(); it++){
        cout<<it->second<<" ";
    }
}