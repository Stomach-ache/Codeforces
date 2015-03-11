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
main(void) {
  	int n, x;
  	scanf("%d %d", &n, &x);
	for (int i = 0; i < n; i++) {
	  	scanf("%d %d %d", &a[i].t, &a[i].h, &a[i].m);
	}
	int ans = 0;
	for (int tt = 0; tt < 2; tt++) {
		memset(vis, false, sizeof(vis));
		int cnt = 0, curt = tt, curx = x;
		while (1) {
		  	int maxM = -1, ii = 0;
			for (int i = 0; i < n; i++) {
		  		if (vis[i] || curt != a[i].t || curx < a[i].m) continue;
				if (maxM < a[i].m) {
			  		maxM = a[i].m;
					ii = i;
				}
			}
			if (maxM == -1) break;
			vis[ii] = true;
			curx += maxM;
			cnt++;
			curt ^= 1;
		}
		ans = max(ans, cnt);
	}
	printf("%d\n", ans);

	return 0;
}
