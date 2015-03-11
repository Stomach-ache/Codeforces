/*************************************************************************
    > File Name: C.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年10月19日 星期日 18时10分27秒
    > Propose: 
 ************************************************************************/
#include <set>
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
const int MAX_N = 5005;
typedef long long LL;
LL dp[MAX_N][MAX_N], sum[MAX_N];

int main(void) {
  	ios::sync_with_stdio(false);
  	LL n, a, b, k;
	cin >> n >> a >> b >> k;

	dp[0][a] = 1;
	for (int i = 1; i <= k; i++) { 
	  	for (int j = 1; j <= n; j++) sum[j] = (sum[j - 1] + dp[i - 1][j]) % MOD;
	  	for (int j = 1; j <= n; j++) {
		  	if (j == b) continue;	
			if (j < b) {
			  	int lb = 1, ub = (b + j) / 2;
				if ((b + j) % 2 == 0) ub--;
				dp[i][j] = (sum[ub] - sum[lb - 1] - dp[i - 1][j]) % MOD;
			} else {
			  	int lb = (b + j) / 2, ub = n;
				dp[i][j] = (sum[ub] - sum[lb] - dp[i - 1][j]) % MOD;
			}
		}
	}
	LL res = 0;
	for (int i = 1; i <= n; i++) (res += dp[k][i]) %= MOD;
	cout << (res + MOD) % MOD << endl;

	return 0;
}
