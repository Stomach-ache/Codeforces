/*************************************************************************
    > File Name: C.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年05月22日 星期四 00时54分59秒
    > Propose: 
 ************************************************************************/

#include <cmath>
#include <string>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n, k, d;
int dp[105][105][2]; //dp[i][j][0..1]: the number of methods that go down until level i and sum is j . 0- none beyond d. 1-at least one beyond d
#define mod (1000000007)

void
solve() {
  	memset(dp, 0, sizeof(dp));
	for (int i = 1; i < d; i++) {
	  	dp[1][i][0] = 1;
	}
	for (int i = d; i <= k; i++) {
	  	dp[1][i][1] = 1;
	}
	for (int i = 2; i <= n; i++) {
	  	for (int j = i; j <= n; j++) {
		  	for (int t = 1; t < d && t <= j; t++) {
			  	dp[i][j][0] += dp[i-1][j-t][0];
				dp[i][j][0] %= mod;
			}
			for (int t = d; t <= j && t <= k; t++) {
			  	dp[i][j][1] += dp[i-1][j-t][0];
				dp[i][j][1] %= mod;
			}
			for (int t = 1; t <= j && t <= k; t++) {
				dp[i][j][1] += dp[i-1][j-t][1];
				dp[i][j][1] %= mod;
			}
		}
	}
}

int
main(void) {
  while (~scanf("%d %d %d", &n, &k, &d)) {
		solve();
		int ans = 0;
		// level will not exceed "n"
		for (int i = 1; i <= n; i++) {
		  	ans += dp[i][n][1];
			ans %= mod;
		}
		printf("%d\n", ans);
  }

  return 0;
}
