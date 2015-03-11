/*************************************************************************
    > File Name: D.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年10月17日 星期五 21时39分21秒
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
const int MAX_N = 200050;
int dp[MAX_N];

int main(void) {
  	ios_base::sync_with_stdio(false);
	int r, g;
	cin >> r >> g;
	int h = 1;
	while (h * (h + 1) / 2 <= r + g) h++;
	h--;

	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (int i = 1; i <= h; i++) {
	  	for (int j = r; j >= i; j--) {
		  	dp[j] = (dp[j] + dp[j - i]) % MOD;
		}
	}
	h = h * (h + 1) / 2;
	int res = 0;
	for (int i = 0; i <= r; i++) if (i + g >= h) res = (res + dp[i]) % MOD;
	cout << res << endl;

	return 0;
}
