/*************************************************************************
    > File Name: A.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年06月13日 星期五 23时51分17秒
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

struct node {
  	int t, h, m;
};
node a[2005];
bool vis[2005];

int
cmp(node a, node b) {
  	return a.h < b.h;
}

int
main(void) {
  	int n, x;
  	scanf("%d %d", &n, &x);
	for (int i = 0; i < n; i++) {
	  	scanf("%d %d %d", &a[i].t, &a[i].h, &a[i].m);
	}
	sort(a, a + n, cmp);
	int ans = 0;
	int pre = -1;
	memset(vis, false, sizeof(vis));
	while (1) {
	  	int maxM = -1, ii = 0;
		for (int i = 0; i < n && x >= a[i].h; i++) {
		  	if (vis[i]) continue;
			if (pre == a[i].t) continue;
			if (maxM < a[i].m) {
			  	maxM = a[i].m;
				ii = i;
			}
		}
		if (maxM == -1) break;
		vis[ii] = true;
		x += maxM;
		ans++;
		pre = a[ii].t;
	}
	printf("%d\n", ans);

	return 0;
}
