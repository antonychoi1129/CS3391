#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);

	int T, N, wall, wallNext, high, low;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		high = low = 0;
		cout << "Case " << i << ":";
		cin >> N >> wall;
		while (N-->1) {
			cin >> wallNext;
			if (wall != wallNext) {
				if (wallNext > wall) high++;
				else low++;
				wall = wallNext;
			}
		}
		cout << " " << high << " " << low << endl;
	}
	return 0;
}
