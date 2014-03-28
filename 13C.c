/*
	dp, sorting
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_N (5000 + 5)
#define min(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;
int a[MAX_N], b[MAX_N], n;
ll dp[2][MAX_N];

int 
cmp(const void *x, const void *y) 
{
	return *(int*)x - *(int*)y;
}

int 
main(void)
{
	while (~scanf("%d", &n) && n) {
		int i, j;
		for (i = 1; i <= n; i++) { 
			scanf("%d", a + i);
			b[i] = a[i];
		}

		qsort(b + 1, n, sizeof(int), cmp);

		dp[0][1] = abs((ll)a[1] - b[1]);
		for (i = 2; i <= n; i++) {
			dp[0][i] = min(dp[0][i-1], abs((ll)a[1] - b[i]));
		}
		int f = 0;
		for (i = 2; i <= n; i++) {
			dp[f^1][1] = dp[f][1] + abs((ll)a[i] - b[1]);

			for (j = 2; j <= n; j++)
				dp[f^1][j] = min(dp[f^1][j-1], dp[f][j] + abs((ll)a[i] - b[j]));
			f ^= 1;
		}

		printf("%lld\n", dp[f][n]);
	}

	return 0;
}