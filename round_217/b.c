/*************************************************************************
    > File Name: b.c
    > Author: Stomach_ache
    > Mail: 1179998621@qq.com 
    > Created Time: 2013年12月07日 星期六 15时38分13秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int n, vis[105][105], mi[105];

int main(void) {
	while (~scanf("%d", &n)) {
		memset(vis, 0, sizeof(vis));
		int i, j;
		for (i = 1; i <= n; i++) {
			scanf("%d", &mi[i]);
			for (j = 1; j <= mi[i]; j++) {
				int m;
				scanf("%d", &m);
				vis[i][m] = 1;
			}
		}
		for (i = 1; i <= n; i++) {
			int res = 1;
			for (j = 1; j <= n; j++) {
				if (j == i)
					continue;
				if (mi[j] > mi[i])
					continue;
				if (mi[j] == mi[i]) {
					int k, f = 1;
					for (k = 1; k <= 100; k++) {
						if (vis[i][k]) {
							if (!vis[j][k]) {
								f = 0;
								break;
							}
						}
					}
					if (f) {
						res = 0;
						break;
					}
				}
				else {
					int k, f = 1;
					for (k = 1; k <= 100; k++) {
						if (vis[j][k]) {
							if (!vis[i][k]) {
								f = 0;
								break;
							}
						}
					}
					if (f) {
						res = 0;
						break;
					}
				}
			}
			if (res)
				puts("YES");
			else
				puts("NO");
		}
	}

	return 0;
}
