#include <iostream>
#include <vector>
using namespace std;

int n,m,b;
int time = 1000000000, aim1 = 256, aim2 = 0, tmp, height;
int matrix[500][500];

int even(int aim){
    tmp = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(tmp>=time) return time;
            int comp = matrix[i][j] - aim;
            if(comp>=0) tmp += 2*comp;
            else tmp -= comp;
        }
    }
    return tmp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin>>n>>m>>b;
    aim2 += b;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
            if(aim1>matrix[i][j]) aim1 = matrix[i][j];
            aim2 += matrix[i][j];
        }
    }
    if(aim1!=0) aim1--;
    aim2 /= (n*m); 
    for(int i=aim2;i>=aim1;i--){
        tmp = even(i);
        if(time>tmp){
            time = tmp;
            height = i;
        }
    }
    cout<<time<<' '<<height;
}