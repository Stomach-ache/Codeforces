/*************************************************************************
    > File Name: a.c
    > Author: Stomach_ache
    > Mail: 1179998621@qq.com 
    > Created Time: 2013年11月24日 星期日 23时30分00秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void) {
	int n;
	while (~scanf("%d", &n)) {
		int i, j, a[5], ans = -1, fir, sec;
		for (i=1; i<=4; i++) {
			scanf("%d %d %d %d", &a[1], &a[2], &a[3], &a[4]);
			if (a[1]+a[3] <= n) {
				ans = i;
				fir = a[1];
				sec = n-fir;
			}
			else if (a[1]+a[4] <= n) {
				ans = i;
				fir = a[1];
				sec = n-fir;
			}
			else if (a[2]+a[3] <= n) {
				ans = i;
				fir = a[2];
				sec = n-fir;
			}
			else if (a[2]+a[4] <= n) {
				ans = i;
				fir = a[2];
				sec = n-fir;
			}
		}
		if (ans == -1)
			puts("-1");
		else
			printf("%d %d %d\n", ans, fir, sec);
	}

	return 0;
}
