/*************************************************************************
    > File Name: c.c
    > Author: Stomach_ache
    > Mail: 1179998621@qq.com 
    > Created Time: 2013年12月07日 星期六 16时09分44秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max(x, y) ((x) > (y) ? (x) : (y))
int n, m;
int a[5005];

int cmp(const void *x, const void *y) {
	return (*(int*)x) - (*(int*)y);
}

int main(void) {
	while (~scanf("%d %d", &n, &m)) {
		int i, j;

		for (i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		
		qsort(a, n, sizeof(int), cmp);

		int mx = -1;
		for (i = 0, j = 0; i < n; i = j) {
			while (j < n && a[j] == a[i]) j++;
			mx = max(mx, j - i);
		}
		if (mx <= n - mx) 
			printf("%d\n", n);
		else 
			printf("%d\n", 2 * (n - mx));

		for (i = 0; i < n; i++) 
			printf("%d %d\n", a[i], a[(i + mx) % n]);
	}

	return 0;
}
