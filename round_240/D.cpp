#include <cstdio>
#include <cstring>
// pre compile
#include <bits/stdc++.h>

#define mod 1000000007
int n, k;
// dp[len][last]
int dp[2005][2005]; 

int main(void) {
	while (~scanf("%d %d", &n, &k)) {
		memset(dp, 0, sizeof(dp));

		// dp[1][i] = 1
		for (int i = 1; i <= n; i++)
			dp[1][i] = 1;

		for (int i = 2; i <= k; i++) {
			for (int j = 1; j <= n; j++) {
				for (int t = j; t <= n; t += j) {
					dp[i][t] += dp[i-1][j];
					dp[i][t] %= mod;
				}
			} 
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
			ans = (ans + dp[k][i]) % mod;
		printf("%d\n", ans);
	}

	return 0;
}
