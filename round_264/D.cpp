/*************************************************************************
    > File Name: D.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年08月30日 星期六 16时31分58秒
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

int n, k, a[6][1002];
int dp[6][1002];
bool vis[1002];

int main(void) {
  	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i <= k; i++) for (int j = 1; j <= n; j++) cin >> a[i][j];
	for (int i = 1; i <= k; i++) {
	  	for (int j = 1; j <= n; j++) {
		  	dp[i][j] = j;
			if (i == 1) continue;
			int tmp = 10000;
		  	for (int k = 1; k <= n; k++) {
			  	tmp = max(tmp, min(tmp, dp[i - 1][a[i][k]]));
			}
			dp[i][j] = tmp + 1;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) ans = max(ans, dp[k][i]);
	cout << ans << endl;
	return 0;
}
