#include<iostream>
#include<queue>
using namespace std;

struct task {
	int index;
	int arvTime;
	int pcsTime;
	task(int i, int sT, int pT) {
		index = i;
		arvTime = sT;
		pcsTime = pT;
	}
	task() {
		index = arvTime = pcsTime = NULL;
	}
};

int main() {
	ios::sync_with_stdio(false);
	int n;
	int i;

	while (cin >> n) {
		queue<task> hghPqueue = queue<task>();
		queue<task> lowPqueue = queue<task>();
		int tasksEndTime[100];
		int r, w;   //arriving time R, processing time W
		bool p; //priority level P

		for (i = 0; i < n; i++) {
			cin >> r >> w >> p;
			if (p) lowPqueue.push(task(i, r, w));
			else hghPqueue.push(task(i, r, w));
		}

		task lpqFront, hpqFront;
		int prevEndTime = 0;
		int startTime;
		while (true) {
			if (hghPqueue.empty()) {
				while (!lowPqueue.empty()) {
					lpqFront = lowPqueue.front();

					startTime = lpqFront.arvTime;
					if (startTime < prevEndTime) startTime = prevEndTime;

					prevEndTime = tasksEndTime[lpqFront.index] = startTime + lpqFront.pcsTime;
					lowPqueue.pop();
				}
				break;
			}

			if (lowPqueue.empty()) {
				while (!hghPqueue.empty()) {
					hpqFront = hghPqueue.front();

					startTime = hpqFront.arvTime;
					if (startTime < prevEndTime) startTime = prevEndTime;

					prevEndTime = tasksEndTime[hpqFront.index] = startTime + hpqFront.pcsTime;
					hghPqueue.pop();
				}
				break;
			}

			lpqFront = lowPqueue.front();
			hpqFront = hghPqueue.front();

			if (hpqFront.arvTime <= lpqFront.arvTime || prevEndTime>=hpqFront.arvTime) {
				startTime = hpqFront.arvTime;
				if (startTime < prevEndTime) startTime = prevEndTime;

				prevEndTime = tasksEndTime[hpqFront.index] = startTime + hpqFront.pcsTime;
				hghPqueue.pop();
			}
			else {
				startTime = lpqFront.arvTime;
				if (startTime < prevEndTime) startTime = prevEndTime;

				prevEndTime = tasksEndTime[lpqFront.index] = startTime + lpqFront.pcsTime;
				lowPqueue.pop();
			}
		}

		for (i = 0; i < n; i++) {
			if (i != 0) cout << ' ';
			cout << tasksEndTime[i];
		}
		cout << endl;
	}

	return 0;
}