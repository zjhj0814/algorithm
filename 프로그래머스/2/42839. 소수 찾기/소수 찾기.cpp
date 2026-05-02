#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

int count = 0;
set<int> primes;

bool is_prime(int number){
    if(primes.find(number) != primes.end()) return false; // 이미 찾은 소수는 패스
    if(number == 0) return false;
    if(number == 1) return false;
    else if(number == 2) return true;
    else if(number == 3) return true;
    for(int i=2;i*i<=number;i++){
        if(number % i == 0) return false;
    }
    return true;
}

// 원본 numbers, 지금까지 만들어진 문자열 answer, 지금까지 만들어진 소수의 개수
void track(string& numbers, string& current_str, set<int>& used_index){
    if(current_str.size() == numbers.size()){
        return;
    }
    for(int i=0;i<numbers.size();i++){ 
        if(used_index.find(i) != used_index.end()) continue; // 사용한 문자라면 패스
        string next = current_str + numbers[i]; // 지금까지 만든 문자열
        used_index.insert(i);
        int next_num = stoi(next);
        if(is_prime(next_num)){
            // cout<<next<<endl;
            primes.insert(next_num);
            count++;
        }
        track(numbers, next, used_index);
        used_index.erase(i);
    }
}

int solution(string numbers) {
    set<int> used_index;
    string current_str = "";
    track(numbers,current_str,used_index);
    return count;
}