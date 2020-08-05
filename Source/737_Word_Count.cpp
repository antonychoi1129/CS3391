#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	string wordArray[695];
	int i = 0;
	while (cin >> wordArray[i++]);
	i-=1;
	sort(wordArray, wordArray + i);

	int count = 1;
	for (int j = 0; j < i; j++) {
		if (wordArray[j].compare(wordArray[j + 1]) != 0) {
			cout << wordArray[j] << " " << count << endl;
			count = 1;
		}else
			count++;
	}
	return 0;
}
