/*************************************************************************
    > File Name: 101B.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年07月19日 星期六 15时22分41秒
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

const int maxn = 100005;
const int mod = 1000000007;
typedef pair<int, int> pii;
typedef long long LL;
#define X first
#define Y second
int n, m;
pii a[maxn];
int dp[maxn], sum[maxn], b[maxn];

int
main(void) {
  	scanf("%d %d", &n, &m);
	int s, t;
	for (int i = 0; i < m; i++) {
	  	scanf("%d %d", &s, &t);
		a[i].X = t, a[i].Y = s;
		b[i] = t;
	}
	sort(b, b+m);
	sort(a, a+m);
	//dp[0] = sum[0] = 0; 
	for (int i = 0; i < m; i++) {
		  int left = lower_bound(b, b+m, a[i].Y) - b;
		  int right = lower_bound(b, b+m, a[i].X) - b;
		  //if (a[i].X == a[right].X) right--;
//		  cout << i << '-' << left << '-' << right << endl;
		  if (a[i].Y == 0) dp[i]++;
		  dp[i] = (dp[i] + sum[right] - sum[left] + mod) % mod;
		  sum[i+1] = (sum[i] + dp[i]) % mod;
	}
//	for (int i = 1; i <= m; i++) cout << dp[i] << endl;
	int ans = 0;
	for (int i = 0; i < m; i++) if (a[i].X == n) ans = (ans + dp[i]) % mod;
	printf("%d\n", ans);
	
	return 0;
}

