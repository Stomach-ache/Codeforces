/*************************************************************************
    > File Name: c.c
    > Author: Stomach_ache
    > Mail: 1179998621@qq.com 
    > Created Time: 2013年11月25日 星期一 00时28分07秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max(x,y) ((x)>(y)?(x):(y))

int n, k, a[105], b[105], dp[10005][10005];

int main(void) {
	while (~scanf("%d %d", &n, &k)) {
		int i, j;
		for (i=1; i<=n; i++)
			scanf("%d", &a[i]);
		for (i=1; i<=n; i++)
			scanf("%d", &b[i]);

		memset(dp, 0, sizeof(dp));
		for (i=1; i<=n; i++) {
			for (j=a[i]; j<=10000; j++) {
				dp[a[i]][b[i]%k]=max(dp[a[i]][b[i]%k],a[i]);

				int tmp = j%k<b[i]?j%k+k-b[i]:j%k-b[i];
				dp[j][j%k] = max(dp[j][j%k], dp[j-a[i]][tmp]+a[i]);
			}
		}

		int ans = 0;
		for (i=0; i<=10000; i++)
			ans = max(ans, dp[i][0]);

		if (ans == 0)
			puts("-1");
		else
			printf("%d\n", ans);
	}

	return 0;
}
