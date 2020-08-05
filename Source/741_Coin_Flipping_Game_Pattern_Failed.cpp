#include <iostream>
#include <math.h>
using namespace std;

int n, m;
int coinPattern[1023];

int bin2dec(string bin, int bits){
	int ans = -pow(2, bits - 1) * (bin[0] - '0');
	for (int i = 1; i < bits; i++)
		ans += (bin[i] - '0') * pow(2, bits - i - 1);

	if (ans < 0) ans = abs(ans + 1);
	return ans;
}


int main(){
	string input;
	int patternCount, rowCount;
	int maxSamePCount;
	int i;


	while (cin >> n >> m) {
		//Init
		for (i = 0; i < pow(2, m); i++)
			coinPattern[i] = 0;

		//Get coins
		for (i = 0; i < n; i++) {
			cin >> input;
			coinPattern[bin2dec(input, m)]++;
		}
		//Analysis
		if (n == 1 || m == 1) {
			cout << m * n << endl;
			continue;
		}
		patternCount = rowCount = 0;
		maxSamePCount = 0;
		for (i = 0; i < pow(2, m); i++)
			if (coinPattern[i] > 0) {
				patternCount++;
				rowCount += coinPattern[i];
				if (coinPattern[i] > maxSamePCount) maxSamePCount = coinPattern[i];

				if (rowCount >= n) break;
			}
		if (patternCount == 1) cout << n * m << endl;
		else{

		}
	}
	return 0;
}
