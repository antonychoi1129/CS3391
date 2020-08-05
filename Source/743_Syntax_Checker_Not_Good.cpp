#include <iostream>
#include <string>
using namespace std;

int main(){
	ios::sync_with_stdio(false);

	string line;
	bool match;
	bool mismatch;
	char open[3] = {'(', '[', '{'};
	char close[3] = {')', ']', '}'};

	int i, j, k, n;

	while (getline(cin, line)) {
		//Find unmatched closing bracket
		match = true;
		for (i = 0; i < line.length() && match; i++) {
			mismatch = false;
			for (j = 0; j < 3; j++) {
				if (line[i] == close[j]) {
					match = false;
					for (k = i - 1; k >= 0; k--) {
						for (n = 0; n < 3; n++) {
							if (line[k] == open[j]) continue;
							if (line[k] == open[n]) {
								mismatch = true;
								break;
							}
						}
						if (mismatch) break;

						if (line[k] == open[j]) {
							match = true;
							//ignore'em forever
							line[k] = line[i] = ' ';
							break;
						}
					}
					if (!match) {
						cout << i + 1 << endl;
						break;
					}
				}
			}
		}
		if (!match) continue;

		//Find remaining unmatched opening bracket
		match = true;
		for (i = 0; i < line.length() && match; i++) {
			for (j = 0; j < 3; j++) {
				if (line[i] == open[j]) {
					match = false;
					cout << i + 1 << endl;
					break;
				}
			}
		}
		if (!match) continue;

		cout << "Success" << endl;
	}
	return 0;
}
