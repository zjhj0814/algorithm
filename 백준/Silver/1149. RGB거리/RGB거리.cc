#include <iostream>
#include <vector>
using namespace std;

vector<int> cost[1002]; //0: 빨강, 1:초록, 2: 파랑
int matrix[1002][1002]; //[지금까지 걸린 최소 비용][칠한 색상]

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin>>n;
    int input;
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++){
            cin>>input;
            cost[i].push_back(input);
        }
    }

    matrix[1][0] = cost[1].at(0);
    matrix[1][1] = cost[1].at(1);
    matrix[1][2] = cost[1].at(2);

    for(int i=2;i<=n;i++){
        matrix[i][0] = min(matrix[i-1][1], matrix[i-1][2]) + cost[i].at(0);
        matrix[i][1] = min(matrix[i-1][0], matrix[i-1][2]) + cost[i].at(1);
        matrix[i][2] = min(matrix[i-1][0], matrix[i-1][1]) + cost[i].at(2);
    }

    cout<<min(matrix[n][0],min(matrix[n][1],matrix[n][2]));
}