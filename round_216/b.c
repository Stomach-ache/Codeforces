/*************************************************************************
    > File Name: b.c
    > Author: Stomach_ache
    > Mail: 1179998621@qq.com 
    > Created Time: 2013年11月29日 星期五 23时39分11秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int n, k, l, r, sa, sk, a[1005];

int main(void) {
	while (~scanf("%d %d %d %d %d %d", &n, &k, &l, &r, &sa,&sk)) {
		int i;
		for (i=1; i<=n; i++)
			a[i] = l;
		int d = (sk-l*k);
		while (d >= k) {
			for (i=1; i<=k; i++)
				a[i]++;
			d -= k;
		}
		int lf = sa-(n-k)*l;
		for (i=1; i<=d; i++)
			a[i]++;
		for (i=1; i<=k; i++)
			lf -= a[i];
		while (lf && lf>=n-k) {
			for (i=k+1; i<=n; i++)
				a[i]++;
			lf -= n-k;
		}
		for (i=k+1; i<=k+lf; i++)
			a[i]++;
		for (i=1; i<=n; i++)
			printf("%d%c", a[i], i==n ? '\n' : ' ');
	}

	return 0;
}
