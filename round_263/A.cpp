/*************************************************************************
    > File Name: A.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年08月26日 星期二 22时05分28秒
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

typedef long long LL;
int n, a[300050];
LL sum[300050];

LL dfs(int l, int r, int turn) {
  	if (l == r) {
	  	if (turn) return 0;
		return a[l];
	}
	LL res = 0;
	if (!turn) {
	  	res = sum[r] - sum[l - 1];
		res += dfs(l, r, turn^1);
		return res;
	}
	res = dfs(l, l+1, turn^1) + dfs(l+2, r, turn^1);
	return res;
}

int main(void) {
  	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	sort(a + 1, a + n + 1);
	sum[n] = a[n];
	for (int i = n - 1; i >= 1; i--) {
		sum[i] = sum[i + 1] + a[i];
	}
	LL ans = sum[1];
	for (int i = 1; i < n; i++) {
	  	ans += sum[i];
	}
	//LL ans = dfs(1, n, 0);
	printf("%lld\n", ans);
}
