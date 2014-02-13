#include <stdio.h>
#include <stdlib.h>

int n, k, a[300005];

int cmp(const void *x, const void *y) {
	return *(int*)x - *(int*) y;
}

int main(void) {
	while (~scanf("%d %d", &n, &k)) {
		int i;
		for (i=0; i<n; i++) 
			scanf("%d", &a[i]);
		qsort(a, n, sizeof(int), cmp);

		int ans = a[0];
		/* k %= ans; */
		while (1) {
			if (a[0]-ans > k) {
				ans = 1;
				break;
			}
			if (ans == 1)
				break;
			int flag = 1;
			for (i=0; i<n; i++) {
				if (a[i]%ans > k) {
					flag = 0;
					break;
				}
			}
			if (flag)
				break;
			ans--;
		}
		printf("%d\n", ans);
	}

	return 0;
}
