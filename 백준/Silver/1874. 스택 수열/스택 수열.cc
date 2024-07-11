#include<stack>
#include<vector>
#include<iostream>
using namespace std;

int main() {
	stack<unsigned int> s;
	vector<char> log;
	unsigned int N, temp;
	scanf("%u", &N);
	s.push(1);
	log.push_back('+');
	unsigned int maximum = 1; //stack에 넣은 값 중 최댓값
	while(N--) {
		scanf("%u", &temp);
		if (temp > maximum) {
			for (unsigned int i = maximum + 1; i <= temp; i++) { //maximum+1~temp까지 스택에 넣기
				s.push(i);
				log.push_back('+');
			}
			maximum = temp;
			s.pop();
			log.push_back('-');
		}
		else if (temp == maximum) {
			s.pop();
			log.push_back('-');
		}
		else { //temp<maximum
			if (s.top() == temp) {
				s.pop();
				log.push_back('-');
			}
			else {
				printf("NO");
				return 0;
			}
		}
	}
	for (unsigned int i = 0; i < log.size(); i++) {
		printf("%c\n", log[i]);
	}
}