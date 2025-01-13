#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> positive;
vector<int> negative;

int main(){
    int n;
    cin>>n;
    int flag0, flag1;
    flag0 = flag1 = false;
    while(n--){
        int temp;
        cin>>temp;
        if(temp>1) positive.push_back(temp);
        else if(temp==1) flag1++;
        else negative.push_back(temp);
    }

    //양수와 음수의 절댓값이 큰 순서로 정렬
    sort(positive.begin(), positive.end(), greater<int>());
    sort(negative.begin(), negative.end());

    int answer = 0;
    int i = 0;
    if(!positive.empty()){
        while(i<positive.size()){
            if(i+1<positive.size()){
                answer += positive[i]*positive[i+1];
                i+=2;
            }
            else{
                answer += positive[i];
                i+=1;
            }
        }
    }
    i = 0;
    if(!negative.empty()){
        while(i<negative.size()){            
            if(i+1<negative.size()){
                answer+= negative[i]*negative[i+1];
                i+= 2;
            }
            else{
                answer += negative[i];
                i+=1;
            }
        }
    }
    if(flag1) answer+=flag1;
    cout<<answer;
}