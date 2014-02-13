/*************************************************************************
    > File Name: 368B.c
    > Author: Stomach_ache
    > Mail: 1179998621@qq.com 
    > Created Time: 2013年11月28日 星期四 14时17分33秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int n, m, a[100005], vis[100005], sum[100005];

int main(void) {
	while (~scanf("%d %d", &n, &m)) {
		int i;
		for (i=1; i<=n; i++) 
			scanf("%d", &a[i]);

		sum[n+1] = 0;
		memset(vis, 0, sizeof(vis));
		for (i=n; i>=1; i--) {
			if (!vis[a[i]]) {
				vis[a[i]] = 1;
				sum[i] = sum[i+1]+1;
			}
			else
				sum[i] = sum[i+1];
		}
		while (m--) {
			int li;
			scanf("%d", &li);
			printf("%d\n", sum[li]);
		}
	}

	return 0;
}
