/*************************************************************************
    > File Name: C.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年07月17日 星期四 22时30分45秒
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

int n, a[5005], rmp[5005][20];

void
rmp_init() {
  	for (int i = 1; i <= n; i++) rmp[i][0] = a[i];
	for (int j = 1; (1<<j) <= n; j++) {
	  	for (int i = 1; i + (1<<(j-1)) -1 <= n; i++) {
		  	rmp[i][j] = min(rmp[i][j-1], rmp[i+(1<<(j-1))][j-1]);
		}
	}
}

int
RMP(int L, int R) {
  	int k = (int)log2(R - L + 1.0);
	return min(rmp[L][k], rmp[R-(1<<k)+1][k]);
}

int
solve(int L, int R, int d) {
  	if (R == L) return 1;
	int m = RMP(L, R);
	if (m-d >= (R - L + 1)) return R - L + 1;
	int res = m - d;
	int i = L, j = R;
	while (m == a[i]) i++;
	while (m == a[j]) j--;
	int left = i;
	for (int k = i+1; k <= j; k++) {
	  	if (m == a[k]) {
		  	res += solve(left, k-1, m);
			left = k + 1;
		}
	}
	if (left <= j) {
	  	res += solve(left, j, m);
	}
	return min(R - L + 1, res);
}

int
main(void) {
  	while (~scanf("%d", &n)) {
	  	for (int i = 1; i <= n; i++) scanf("%d", a+i);
		rmp_init();
		int ans = solve(1, n, 0);
		printf("%d\n", ans);
	}

	return 0;
}
