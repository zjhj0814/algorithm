#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int po_num[4001];
int ne_num[4001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;
    int tmp;
    int sum = 0;
    int max_1 = -4000; int min_1 = 4000;
    for(int i=0; i<N; i++){
        cin>>tmp;
        sum += tmp;
        if(max_1<tmp) max_1 = tmp;
        if(min_1>tmp) min_1 = tmp;
    
        if(tmp>=0) po_num[tmp]++;
        else ne_num[abs(tmp)]++; 
    }
    //1. 산술평균
    double average = sum/N + ((double)(sum%N))/N;
    average = round(average);
    if(average==-0) average=0;
    cout<<round(average)<<'\n';

    //2. 중앙값
    const int medium = N/2+1;
    int th = 0;
    for(int i=4000; i>=0; i--){
        if(ne_num[i]!=0) th+=ne_num[i];
        if(th>=medium){
            cout<<-i<<'\n';
            break;
        }
    }
    if(th<medium){
        for(int i=0; i<4001; i++){
            if(po_num[i]!=0) th+=po_num[i];
            if(th>=medium){
                cout<<i<<'\n';
                break;
            }
        }
    }

    //3. 최빈값
    int max = 0; //빈도수
    queue<int> q;
    for(int i=4000; i>=0; i--){
        if(ne_num[i]!=0){
            if(max<ne_num[i]){
                max = ne_num[i];
                while(!q.empty()){
                    q.pop();
                }
                q.push(-i);
            }
            else if(max==ne_num[i]){
                q.push(-i);
            }
        }
    }
    for(int i=0; i<4001; i++){
        if(po_num[i]!=0){
            if(max<po_num[i]){
                max = po_num[i];
                while(!q.empty()){
                    q.pop();
                }
                q.push(i);
            }
            else if(max==po_num[i]){
                q.push(i);
            }
        }
    }
    if(q.size()!=1){
        q.pop();
        cout<<q.front()<<'\n';
    }
    else cout<<q.front()<<'\n';

    //4. 범위 출력
    cout<<abs(max_1-min_1);
}