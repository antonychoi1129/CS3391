#include <stdio.h>
#include <algorithm>
using namespace std;
int N, C;
bool okwor(int crazy, int *rooms, int mid) {
	int assigned = 1;
	int prevRoomLct = rooms[0];
	for (int i = 1; i < N && assigned < crazy; i++)
		if (rooms[i] - prevRoomLct >= mid) {
			assigned++;
			prevRoomLct = rooms[i];
		}
	return assigned >= crazy;
}


int main() {
	int T;

	scanf("%i", &T);
	for (int cases = 0; cases < T; cases++) {
		scanf("%i%i",&N,&C);

		int rooms[100000];
		for (int nlines = 0; nlines < N; nlines++)
			scanf("%i", &rooms[nlines]);

		sort(rooms, rooms + N);
		int min, max;
		min = 1;
		max = (rooms[N - 1] - rooms[0]) / (C - 1);



		while (max - min > 1) {
			int mid = (min + max) / 2;
			if (okwor(C, rooms, mid)) min = mid;
			else max = mid;
		}
		printf("%i\n",min);
	}

	return 0;
}
