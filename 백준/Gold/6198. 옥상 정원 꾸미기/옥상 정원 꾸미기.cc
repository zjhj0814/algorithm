#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, temp;
    long long count=0;
    cin>>N;
    stack<int> tower;
    for(int i=1; i<=N; i++){
        cin>>temp;
        while(!tower.empty()&&tower.top()<=temp) tower.pop(); // 내 앞에 낮거나 같은 애들은 pop하고(어차피 필요없음)
        count+=tower.size(); //나보다 높은 빌딩의 갯수를 세기
        tower.push(temp);
    }
    cout<<count;
}