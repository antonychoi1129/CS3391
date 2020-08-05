#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);

	int T, n, m;
	int max[12000];
	char opt;
	
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;

		cin >> max[0];
		//Deal with the rest
		for (int i = 1; i < n; i++) {
			cin >> max[i];
			if (max[i] < max[i - 1]) max[i] = max[i - 1];
		}
		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> opt;
			switch (opt) {
			case 'm':
				cout << max[n - 1] << endl;
				break;
			case 'r':
				n--;
				break;
			case 'a':
				cin >> max[n];
				if (max[n] < max[n - 1]) max[n] = max[n - 1];
				n++;
			}
		}
	}

	return 0;
}
