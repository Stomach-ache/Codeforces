/*************************************************************************
    > File Name: 439D.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年06月05日 星期四 22时05分00秒
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

#define MAX_N (100005)
#define min(x, y) ((x) < (y) ? (x) : (y))
typedef long long LL;

int n, m;
int a[MAX_N], b[MAX_N];
LL sumA[MAX_N], sumB[MAX_N];

LL
countA(int i) {
  	int pos = lower_bound(b+1, b+m+1, a[i]) - b;
	LL cnt = sumB[m] - sumB[pos-1] - (LL)a[i]*(m-pos+1);
	cnt += (i-1) * (LL)a[i] - sumA[i-1];
	return cnt;
}

LL
countB(int i) {
  	int pos = lower_bound(a+1, a+n+1, b[i]) - a;
	LL cnt = sumB[m] - sumB[i-1] - (LL)b[i]*(m-i+1);
	cnt += (pos-1) * (LL)b[i] - sumA[pos-1];
	return cnt;
}

int
main(void) {
  	while (~scanf("%d %d", &n, &m)) {
	  	for (int i = 1; i <= n; i++) scanf("%d", a+i);
	  	for (int i = 1; i <= m; i++) scanf("%d", b+i);
		sort(a+1, a+n+1);
		sort(b+1, b+m+1);
		sumA[0] = sumB[0] = 0;
		for (int i = 1; i <= n; i++) sumA[i] = sumA[i-1] + a[i];
		for (int i = 1; i <= m; i++) sumB[i] = sumB[i-1] + b[i];
		LL ans = 1e14;
		for (int i = 1; i <= n; i++) {
		  	ans = min(ans, countA(i));
		}
		for (int i = 1; i <= m; i++) {
		  	ans = min(ans, countB(i));
		}
		printf("%lld\n", ans);
	}

	return 0;
}
