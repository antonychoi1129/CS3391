#include <iostream>
#include <queue>
using namespace std;

int main(){

	int N, A, O, L;
	queue<int> q;
	bool a;

	while (cin >> N) {
		for (int i = 0; i < N; i++) {
			cout << "HELLO!1" << endl;
			cin >> A >> O >> L;
			cout << "HELLO!2" << endl;

			while (!q.empty() && q.front() <= A) {
				q.pop();
			}

			a = L >= q.size();
			if (a)
				q.push(O + (A > q.back() ? A : q.back()));
		}
		if (a)
			cout << q.back() - O << endl;
		else
			cout << -1 << endl;

	}
	return 0;
}
