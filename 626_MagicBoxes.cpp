#include <iostream>
#include <algorithm>
#include <math.h> 
#include <vector>
using namespace std;
int main()
{
	int n, m;
	while (cin >> n >> m) {
		int cnt = 0;
        vector<int> cost;
		for (int i = 0; pow(m, i) <= n; i++) {
			cost.push_back(pow(m, i));
			cnt++;
		}
        vector<int> dp(n+1, 0);
		dp[0] = 1;//inital state
		for (int i = 0; i < cnt; i++)
			for (int j = cost[i]; j <= n; j++) {
				dp[j] = dp[j] + dp[j - cost[i]];
				dp[j] = dp[j] % 1000000007;
			}
		cout << dp[n] << endl;
	}
	return 0;
}