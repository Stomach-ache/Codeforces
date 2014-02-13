/*************************************************************************
    > File Name: b.c
    > Author: Stomach_ache
    > Mail: 1179998621@qq.com 
    > Created Time: 2013年11月24日 星期日 23时53分20秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int n, k, a[100005<<1], tmp[100005];

int main(void) {
	while (~scanf("%d %d", &n, &k)) {
		int i, j;
		memset(tmp, 0, sizeof(tmp));
		for (i=0; i<n; i++) {
			scanf("%d", &a[i]);
			//a[i+n] = a[i];
			tmp[i%k] += a[i];
		}
		
		int ans = 0, min = tmp[0];
		for (i=1; i<k; i++) {
			if (min > tmp[i]) {
				min = tmp[i];
				ans = i;

			}
		}
		printf("%d\n", ans+1);
	}

	return 0;
}
