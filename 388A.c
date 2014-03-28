/*
	water....
	sorting, greedy, brute force, binary search.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, vis[105], a[105];

int 
cmp(const void *x, const void *y) {
	return *(int*)x - *(int*)y;
}

int
solve ()
{
	memset(vis, 0, sizeof(vis));
	int cnt = 0, res = 0;
	while ( cnt < n ) {
		int i, tmp = 0;
		for (i = 0; i < n; i++) if ( !vis[i] ) {
			if (a[i] >= tmp) {
				vis[i] = 1;
				tmp++;
			}
		}
		cnt += tmp;
		res += 1;
	}

	return res;
}

int 
main(void)
{
	while (~scanf("%d", &n) && n) {
		int i;
		for (i = 0; i < n; i++) 
			scanf("%d", a+i);
		
		qsort(a, n, sizeof(int), cmp);

		printf("%d\n", solve());
	}

	return 0;
}
