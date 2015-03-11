/*************************************************************************
    > File Name: C.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年09月18日 星期四 23时43分51秒
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

const int MAX_N = 5050;
typedef long long LL;
const LL INF = (LL)1e18;
LL a[MAX_N], sum[MAX_N], dp[MAX_N][MAX_N], n, m, k;

int main(void) {
  	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (LL i = 1; i <= n; i++) cin >> a[i], sum[i] = sum[i-1] + a[i];

	for (int i = 0; i <= n; i++) fill(dp[i], dp[i]+k+1, -INF);
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
	  	for (int j = 0;  j <= k; j++) {
		  	if (j != 0 && i >= m) 
			  	dp[i][j] = max(dp[i][j], dp[i-m][j-1]+sum[i]-sum[i-m]);
			dp[i][j] = max(dp[i][j], dp[i-1][j]);
		}
	}
	cout << dp[n][k] << endl;

	return 0;
}
