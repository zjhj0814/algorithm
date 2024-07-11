#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;

bool isPrime(unsigned int i) {
	if (i <= 1) return false;
	else if (i == 2) return true;
	else if (i%2 == 0) return false;
	else {
		for (unsigned int temp = 3; temp * temp <= i; temp+=2) {
			if (i % temp == 0) return false;
		}
		return true;
	}
}

int main() {
	unsigned int n;
	while (true) {
		scanf("%u", &n);
		if (n == 0) break;
		unsigned int count = 0;
		for (unsigned int i = n + 1; i <= 2*n; i++) {
			if (isPrime(i)) count++;
		}
		printf("%u\n", count);
	}
	
}