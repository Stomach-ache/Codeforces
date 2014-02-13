#include <stdio.h>

int n, k, sum[200000];

int main(void) {
	while (~scanf("%d %d", &n, &k)) {
		int i;
		sum[0] = 0;
		for (i=1; i<=n; i++) {
			int h;
			scanf("%d", &h);
			sum[i] = sum[i-1]+h;
		}
		int max = 0x3f3f3f3f, ans;
		for (i=k; i<=n; i++) {
			if (sum[i]-sum[i-k] < max) {
				max = sum[i]-sum[i-k];
				ans = i-k+1;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}
