/*************************************************************************
    > File Name: 425A.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年04月29日 星期二 22时07分09秒
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

#define max(x,y) ((x) > (y) ? (x) : (y))
int n, k, a[205], b[205], s[205];
bool vis[205];

int
main(void) {
		scanf("%d %d", &n, &k);
		s[0] = 0;
		for (int i = 1; i <= n; i++) {
				scanf("%d", b + i);
				s[i] = s[i-1] + b[i];
		}
	    int ret = -1005;
		for (int i = 1; i <= n; i++) {
				for (int j = 1; j+i-1 <= n; j++) {
						for (int ll = 1; ll <= n; ll++) {
								a[ll] = b[ll];
						}
						memset(vis, false, sizeof(vis));
						int ans = s[j+i-1] - s[j-1];
						/* ans = max(ans, s[j+i-1]-s[j-1]); */
						for (int t = 1; t<=k && t<=i; t++) {
								int min = 1005, mini;
								for (int ll = j; ll <= j+i-1; ll++) {
										if (!vis[ll] && min > a[ll]) {
												min = a[ll];
												mini = ll;
										}
								}
								int tmp = -1005, tmpi;
								for (int ll = 1; ll < j; ll++) {
										if (!vis[ll] && tmp < a[ll]) {
												tmp = a[ll];
												tmpi = ll;
										}
								}
								for (int ll = j+i; ll <= n; ll++) {
										if (!vis[ll] && tmp < a[ll]) {
												tmp = a[ll];
												tmpi = ll;
										}
								}
								if (min >= tmp || tmp == -1005) {
										break;
								} else {
										swap(a[tmpi], a[mini]);
										ans += (tmp - min);
								}
								vis[tmpi] = true;
								vis[mini] = true;
						}
						ret = max(ret, ans);
				}
		}
		printf("%d\n", ret);
		
		return 0;
}
