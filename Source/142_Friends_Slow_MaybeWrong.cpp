#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

bool is_in(unordered_set<int> set, int target){
	return set.find(target) != set.end();
}


int main(){
	ios::sync_with_stdio(false);
	int cases;
	int N, M;
	int A, B;
	int i, j;

	int count;
	bool foundA, foundB;
	int largest, num;

	cin >> cases;
	for (i = 0; i < cases; i++) {
		count = 0;
		cin >> N >> M;
		unordered_set<int> saw;
		vector< unordered_set<int> > groups;

		for (j = 0; j < M; j++) {
			cin >> A >> B;
			foundA = is_in(saw, A);
			foundB = is_in(saw, B);

			if (!foundA && !foundB) {
				unordered_set<int> tempSet;
				tempSet.insert(A);
				tempSet.insert(B);
				groups.push_back(tempSet);
				count++;
				saw.insert(A);
				saw.insert(B);
			}else {
				if (foundA)
					for (int i = 0; i < count; i++)
						if (is_in(groups[i], A)) groups[i].insert(B);
				if (foundB)
					for (int i = 0; i < count; i++)
						if (is_in(groups[i], B)) groups[i].insert(A);
			}
		}
		largest = groups[0].size();
		for (int i = 1; i < count; i++) {
			if (largest >= N) break;
			num = groups[i].size();
			if (num > largest) largest = num;
		}
		cout << largest << endl;
	}
	return 0;
}
