#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *x, const void *y) {
	return *(int*)x - *(int*)y;
}

int b[3005], n, m;

int main(void) {
	while (~scanf("%d %d", &n, &m)) {
		int i;
		for (i=0; i<m; i++) 
			scanf("%d", &b[i]);
		qsort(b, m, sizeof(int), cmp);
		int flag = 1;
		if (b[0]==1 || b[m-1]==n)
			flag = 0;
		for (i=2; i<m && flag; i++) {
			if (b[i]-b[i-2] == 2) {
				flag = 0;
				break;
			}
		}
		if (flag)
			puts("YES");
		else
			puts("NO");
	}

	return 0;
}
