#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, temp;
    cin>>N;
    stack<pair<int, int>> tower;
    tower.push({100000001,0});
    for(int i=1; i<=N; i++){
        cin>>temp;
        while(tower.top().first<temp) tower.pop(); // 내 앞에 작은 애들은 pop하고(어차피 필요없음)
        cout<<tower.top().second<<" "; //나보다 큰 아이가 top()에 존재함
        tower.emplace(temp,i);
    }
}