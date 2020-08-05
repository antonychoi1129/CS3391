#include <iostream>
#include <stack>
using namespace std;

int prt(char c){
	if (c == '*' || c == '/')
		return 7;
	else if (c == '+' || c == '-')
		return 3;
	else return -1;
}


int main(){
	//ios::sync_with_stdio(false);

	int testcases;
	string input;
	string pfString;

	cin >> testcases;
	getline(cin, input);
	getline(cin, input);

	char crt;
	stack<char> aStack = stack<char>();
	for (int t = 0; t < testcases; t++) {
		pfString="";
		do {
			getline(cin, input);
			if (input=="") break;
			crt = input[0];

			if (crt >= '0' && crt <= '9') pfString += crt;

			else if (crt == '(')
				aStack.push('(');

			else if (crt == ')') {
				while (aStack.top() != '(') {
					pfString += aStack.top();
					aStack.pop();
				}
				aStack.pop();	//pop '(' away
			}

			//Must be a operator...
			else{
				while( !aStack.empty() && prt(crt)<=prt(aStack.top()) ){
					pfString+=aStack.top();
					aStack.pop();
				}
				aStack.push(crt);
			}
		} while (input!="");

		while (!aStack.empty()) {
			pfString += aStack.top();
			aStack.pop();
		}
		cout<<pfString<<endl;
		if(t+1<testcases) cout<<endl;
	}

	return 0;
}
