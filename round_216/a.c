/*************************************************************************
    > File Name: a.c
    > Author: Stomach_ache
    > Mail: 1179998621@qq.com 
    > Created Time: 2013年11月29日 星期五 23时30分25秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int n, m, k, a[1005];

int main(void) {
	while (~scanf("%d %d %d", &n, &m, &k)) {
		int i;
		for (i=1; i<=n; i++)
			scanf("%d", &a[i]);
		int ans = 0;
		for (i=1; i<=n; i++) {
			if (a[i] == 1) {
				if (m > 0)
					m--;
				else
					ans++;
			}
			else {
				if (k > 0)
					k--;
				else if(m > 0)
					m--;
				else
					ans++;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}
