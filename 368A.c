/*************************************************************************
    > File Name: 368A.c
    > Author: Stomach_ache
    > Mail: 1179998621@qq.com 
    > Created Time: 2013年11月28日 星期四 14时07分28秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int n, d, a[105], m, used[105];

int cmp(const void *x, const void *y) {
	return *(int*)x - *(int*)y;
}

int main(void) {
	while (~scanf("%d %d", &n, &d)) {
		int i;
		for (i=0; i<n; i++)
			scanf("%d", &a[i]);
		scanf("%d", &m);

		qsort(a, n, sizeof(int), cmp);
		/* memset(used, 0, sizeof(used)); */

		int ans = 0;
		for (i=0; i<n && i<m; i++)
			ans += a[i];
		if (m > n)
			ans -= d*(m-n);

		printf("%d\n", ans);
	}

	return 0;
}
