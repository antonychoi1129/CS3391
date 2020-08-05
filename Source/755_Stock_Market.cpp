#include <iostream>
#include <stack>
using namespace std;

int main(){
	//Dont read, I dont know what Im coding
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int testcases;
	cin >> testcases;
	for (int t = 0; t < testcases; t++) {
		int numOfDay;
		cin >> numOfDay;

		long long int stkPs[numOfDay];
		for (int n = 0; n < numOfDay; n++)
			cin >> stkPs[n];

		stack <int> days = stack<int>();//smallerDays b4 day i
		long long int bigRarea = 0;
		long long int Rarea;
		
		int i = 0;
		while (i <= numOfDay) {
			if (days.empty() || (i<numOfDay && stkPs[i] >= stkPs[days.top()]) )
				days.push(i++);

			else {
				Rarea = stkPs[days.top()];
				days.pop();
				
				if (days.empty()) Rarea *= i;
				else Rarea *= i - days.top() - 1;

				if (Rarea > bigRarea)
					bigRarea = Rarea;
			}
		}
		cout << bigRarea << endl;
	}

	return 0;
}
