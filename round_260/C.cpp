/*************************************************************************
    > File Name: C.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年08月08日 星期五 23时54分40秒
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

const int maxn = 100002;
int a[maxn], n;
typedef long long LL;
int vis[maxn];
LL dp[maxn];

int main(void) {
  	while (~scanf("%d", &n)) {
	  	memset(vis, 0, sizeof(vis));
		int m = -1;
	  	for (int i = 1; i <= n; i++) {
		  	scanf("%d", a + i);
			vis[a[i]]++;
			m = max(m, a[i]); 
		}
		dp[0] = 0;
		dp[1] = vis[1];
		for (int i = 2; i <= m; i++) 
		  	dp[i] = max(dp[i-2]+(LL)i*vis[i], dp[i-1]);
		printf("%lld\n", dp[m]);
	}
	return 0;
}
