/*************************************************************************
    > File Name: 119B.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年07月19日 星期六 11时29分24秒
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

int k, n, q;
int vis[105];
typedef pair<int, int> pii;
pii a[105];

double
min(double x, double y) {
  	return x > y ? y : x;
}

double
max(double x, double y) {
  	return x > y ? x : y;
}

int
main(void) {
  	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
	  	scanf("%d", &a[i].first);
		a[i].second = i;
	}
	scanf("%d", &q);
	//memset(vis, 0, sizeof(vis));
	double mmin = 100.0, mmax = 0.0;
	int count = 0;
	while (q--) {
	  	double tmp = 0.0;
		int b;
	  	for (int i = 0; i < n/k; i++) {
		  	scanf("%d", &b);
			if (!vis[b]) count++;
			vis[b] = 1;
			tmp += a[b].first;
		}
		tmp /= n/k;
		mmin = min(mmin, tmp);
		mmax = max(mmax, tmp);
	}
	if (n - n/k*k < n - count) {
		sort(a+1, a+n+1);	
		double tmp = 0.0, cnt = 0;
		for (int i = 1; i <= n; i++) {
		  	if (!vis[a[i].second]) {
			  	cnt++;
				tmp += a[i].first;
				if (cnt == n/k) break;
			}
		}
		if (cnt == n/k) {
	  		tmp /= cnt;
	  		mmin = min(mmin, tmp);
			mmax = max(mmax, tmp);
		}
		tmp = 0.0, cnt = 0;
		for (int i = n; i > 0; i--) {
		  	if (!vis[a[i].second]) {
			  	cnt++;
				tmp += a[i].first;
				if (cnt == n/k) break;
			}
		}
		if (cnt == n/k) {
		  	tmp /= cnt;
			mmin = min(mmin, tmp);
			mmax = max(mmax, tmp);
		}
	}
	printf("%.17f %.17f\n", mmin, mmax);

	return 0;
}
