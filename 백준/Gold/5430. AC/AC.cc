#include <iostream>
#include <deque>
#include <string>
using namespace std;

//stringstream은 문자열을 스트림으로 처리하여
//텍스트 데이터를 파싱하고 변환하는 데 유용하다
//따라서 문자열 속 숫자를 추출하는 데도 사용하지만
//공백으로 다른 문자와 분리되어 있지 않은 경우에는 사용이 어렵다
//그냥 뜻대로 안 되니까 PS에서 사용하지는 말 것!

deque<int> d;

void parse(const string& arr){
    //문자열에서 숫자를 추출하고 추출한 숫자를 덱에 넣는 함수
    int temp=0;
    for(int i=1; i+1<(int)arr.size(); i++){
        if(arr[i]==','){
            d.push_back(temp);
            temp=0;
        }
        else{
            temp=temp*10+(arr[i]-'0');
        }
    }
    if(temp!=0) d.push_back(temp);
}

void printDeque(int reverse){
    //함수를 정해진 출력대로 출력하는 함수
    cout<<"[";
    if(reverse==0){
        for(int i=0; i<(int)d.size(); i++){
            cout<<d[i];
            if(i+1!=(int)d.size()) cout<<',';
        }
    }
    else{
        for(int i=(int)d.size()-1; i>=0; i--){
            cout<<d[i];
            if(i!=0) cout<<',';
        }
    }
    cout<<"]\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, n;
    string func, arr;
    cin>>T;
    while(T--){
        int reverse=0; //0 그대로, 1 reverse
        int flag=0;
        cin>>func>>n>>arr;
        parse(arr);
        for(char c:func){
            if(c=='R'){
                reverse = (reverse==0)? 1:0;
            }
            else if(c=='D'){
                if(d.empty()){
                    cout<<"error\n";
                    flag=1; //flag 세우기
                    break;
                }
                else{
                    (reverse==0)? d.pop_front():d.pop_back();
                }
            }
        }
        if(flag==0) printDeque(reverse);
        d.clear(); //전역변수 d 초기화
    }
}