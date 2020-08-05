#include <iostream>

using namespace std;

int n, m;
int A[3001], S[3001];
int a_Sum, target_Sum;
int a_Top, s_Top;

void a2s(){
	s_Top++;
	S[s_Top] = A[a_Top];
	a_Top--;
}


bool achievable(int * target){
	if (a_Sum != target_Sum) return false;
	int i;
	bool found;

	for (i = 0; i < n; i++) {
		found = false;

		if (s_Top != -1)
			if (S[s_Top] == target[i]) found = true;

		while (a_Top != -1 && !found) {
			a2s();
			if (S[s_Top] == target[i]) {
				found = true;
				break;
			}
		}

		if (!found) return false;

		s_Top--;
	}

	return true;
}


int main(){
	ios::sync_with_stdio(false);

	int T;
	int target[3001];

	cin >> T;
	for (int i = 0; i < T; i++) {
		a_Sum = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> A[i];
			a_Sum += A[i];
		}
		cin >> m;
		for (int i = 0; i < m; i++) {
			//Init
			a_Top = n - 1;
			s_Top = -1;
			target_Sum = 0;
			for (int i = 0; i < n; i++) {
				cin >> target[i];
				target_Sum += target[i];
			}
			if (achievable(target)) cout << "Aye" << endl;
			else cout << "Impossible" << endl;
		}
	}
	return 0;
}
