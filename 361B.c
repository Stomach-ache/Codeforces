#include <stdio.h>

int main(void) {
	int n, k;
	while (~scanf("%d %d", &n, &k)) {
		if (n == k)
			puts("-1");
		else {
			int i;
			for (i=1; i<n-k; i++) {
				printf("%d ", i+1);
			}
			putchar('1');
			i = n-k;
			if (i < n)
				putchar(' ');
			for (i=n-k+1; i<=n; i++) {
				printf("%d", i);
				if (i != n)
					putchar(' ');
			}
			puts("");
		}
	}

	return 0;
}
