/*************************************************************************
    > File Name: D.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年08月02日 星期六 00时05分52秒
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

int n, a[105], ans[105];

bool ok(int x) {
  	for (int i = 1; i <= n; i++) ans[i] = a[i];

}

int main(void) {
  	scanf("%d", &n);
	int sum = 0;
	for (int i = 1; i <= n; i++) {
	  	scanf("%d", a + i);
		sum += a[i];
	}
	int l = -1, r = sum - n;
	while (l < r) {
	  	int mid = (l + r) / 2;
		if (ok(mid)) {
		  	r = mid;
		} else {
		  	l = mid;
		}
	}
	for (int i = 1; i <= n; i++) 
	  	printf("%d%c", ans[i], i == n ? '\n' : ' ');

	return 0;
}
