#include <iostream>
#include <string>
#include <stack>
using namespace std;

int checker(string line){
	stack<int> openers;
	int lastOpen;
	for (int i = 0; i < line.length(); i++) {
		//Push Opener to stack
		if (line[i] == '(' || line[i] == '[' || line[i] == '{') {
			openers.push(i);
			continue;
		}

		//Close analysis
		if (line[i] == ')' || line[i] == ']' || line[i] == '}') {
			if (openers.empty()) return i;
			lastOpen = line[openers.top()];
			openers.pop();

			switch (lastOpen) {
			case '(':
				if (line[i] == ']' || line[i] == '}')
					return i;
				break;
			case '[':
				if (line[i] == ')' || line[i] == '}')
					return i;
				break;
			case '{':
				if (line[i] == ')' || line[i] == ']')
					return i;
				break;
			}
		}
	}
	//Finishing
	if (!openers.empty()){
		while (openers.size()>1)
			openers.pop();
		return openers.top();
	}

	return -1;
}


int main(){
	ios::sync_with_stdio(false);
	string line;
	int pos;

	while (getline(cin, line)) {
		pos = checker(line);
		if (pos == -1) cout << "Success" << endl;
		else cout << pos + 1 << endl;
	}

	return 0;
}
