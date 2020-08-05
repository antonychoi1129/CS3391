#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int findLove(string num) {
	int max = 0;
	int i = 0;
	
	for(int i=0; i<num.size(); i++)
		if (num[i] - '0' > max) max = num[i] - '0';

	return max;
}

long long int n2d(string num, int base) {
	long long int ans = 0;
	for(int i=0; i<num.size(); i++)
		ans = ans*base+num[i]-'0';
	return ans;
}

bool isMagic(long long int num) {
	double s = floor(sqrt(num));
	return (s * s == num);
}

int main() {
	string input;

	while(cin >> input){
		if (input == "0") break;

		int love = findLove(input)+1;

		for (int i = love; i <100; i++) {
			if (isMagic( n2d(input, i) )) {
				cout << i <<endl;
				break;
			}
			if(i+1==100){
				cout<< 100 <<endl;
			}
		}
	}

	return 0;
}
