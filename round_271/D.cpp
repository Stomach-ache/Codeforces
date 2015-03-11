/*************************************************************************
    > File Name: D.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年10月06日 星期一 23时48分31秒
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
/*Let's fight!!!*/

const int MOD = 1e9 + 7;
int t, k;
int dp[100050], sum[100050];

void dfs(int n) {
  	long long res = 0;
	if (dp[n] != -1) return ;
	if (n >= 1) {
		dfs(n - 1);
		res += dp[n - 1];
	}
	if (n >= k) {
	  	dfs(n - k);
		res = (res + dp[n - k]) % MOD;
	}
	dp[n] = res;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin >> t >> k;
  	memset(dp, -1, sizeof(dp));
	dp[0] = 1;
	for (int i = 1; i <= 100000; i++) if (dp[i] == -1) dfs(i);
	sum[0] = 0;
	for (int i = 1; i <= 100000; i++) sum[i] = (sum[i-1] + (long long)dp[i]) % MOD;
	while (t--) {
	  	int a, b;
		cin >> a >> b;
		cout << (sum[b] - sum[a - 1] + MOD) % MOD << endl;
	}
	return 0;
}
