#include <iostream>
#include <stack>

using namespace std;

int n, m;

bool achievable(stack<int> A, int * target){
	stack<int> S;
	int i;
	bool found;

	for (i = 0; i < n; i++) {
		found = false;

		if (!S.empty())
			if (S.top() == target[i]) found = true;

		while (!A.empty() && !found) {
			S.push(A.top());
			A.pop();
			if (S.top() == target[i]) {
				found = true;
				break;
			}
		}

		if (!found) return false;

		S.pop();
	}

	return true;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	stack<int> A;
	int T;
	int element;

	int target[3001];

	cin >> T;
	for (int i = 0; i < T; i++) {
		A = stack<int>();
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> element;
			A.push(element);
		}
		cin >> m;
		for (int i = 0; i < m; i++) {
			for (int i = 0; i < n; i++)
				cin >> target[i];
			if (achievable(A, target)) cout << "Aye" << endl;
			else cout << "Impossible" << endl;
		}
	}
	return 0;
}
