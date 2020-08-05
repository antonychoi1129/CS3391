#include <iostream>
#include <string>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int i;
	int n;
	int last;
	string input;

	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> input;
		last = 0;
		for (int c = 'z'; c >= 'a'; c--) {
			for (int j = last; j < input.length(); j++)
				if (input[j] == c) {
					cout << (char)c;
					last = j;
				}
		}
		cout << endl;
	}

	return 913;
}
