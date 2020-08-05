#include<iostream>
#include<string>
#include<sstream>
#include<stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string line;
	char c;
	int result;

	while (getline(cin,line)) {
		stack<int> rpns = stack<int>();
		stringstream rpn(line);
		while (rpn >> c) {

			if (c == '+') {
				result = rpns.top();
				rpns.pop();
				result += rpns.top();
				rpns.pop();
				rpns.push(result);
			}
			else if (c == '-') {
				result = rpns.top();
				rpns.pop();
				result = rpns.top() - result;
				rpns.pop();
				rpns.push(result);
			}

			else if (c == '*') {
				result = rpns.top();
				rpns.pop();
				result *= rpns.top();
				rpns.pop();
				rpns.push(result);
			}

			else
				rpns.push(c - '0');
		}
		cout <<rpns.top()<< endl;
	}

	return 0;
}
