/*************************************************************************
    > File Name: A.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年09月11日 星期四 20时34分30秒
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

const int MAX_N = 10005;
const int MAX_K = 105;
bool dp[MAX_N][MAX_K];
int a[MAX_N], n, k;
#define rep(i, n) for (int i = (1); i <= (n); i++)

int main(void) {
  	ios::sync_with_stdio(false);
	cin >> n >> k;
	rep (i, n) cin >> a[i];	

	//memset(dp, false, sizeof(dp));
	//memset(dp[0], true, sizeof(dp[0]));
	dp[0][0] = true;
	rep (i, n) {
	  	for (int j = 0; j < k; j++) {
		  	if (dp[i-1][((j-a[i])%k+k)%k]) dp[i][j] = true;
		  	if (dp[i-1][((j+a[i])%k+k)%k]) dp[i][j] = true;
		}
	}
	if (dp[n][0]) puts("Divisible");
	else puts("Not divisible");

	return 0;
}
