#include <iostream>
#include <vector>
using namespace std;

struct set{
    private:
        int arr[21]{};
    public:
        void add(int x){
            if(arr[x]!=0) return;
            arr[x] = 1;
        }
        void remove(int x){
            if(arr[x]==0) return;
            arr[x] = 0;
        }
        void check(int x){
            if(arr[x]==0) cout<<0<<'\n';
            else cout<<1<<'\n';
        }
        void toggle(int x){
            if(arr[x]==0){
                arr[x] = 1;
            }
            else{
                arr[x] = 0;
            }
        }
        void all(){
            for(int i=1;i<=20;i++){
                arr[i] = 1;
            }
        }
        void empty(){
            for(int i=1;i<=20;i++){
                arr[i] = 0;
            }
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int m;
    string str;
    int par;

    set s;
    cin>>m;
    while(m--){
        cin>>str;
        if(str=="add"){
            cin>>par;
            s.add(par);
        }
        else if(str=="remove"){
            cin>>par;
            s.remove(par);
        }
        else if(str=="check"){
            cin>>par;
            s.check(par);
        }
        else if(str=="toggle"){
            cin>>par;
            s.toggle(par);
        }
        else if(str=="all"){
            s.all();
        }
        else if(str=="empty"){
            s.empty();
        }
    }   
}