#include <stdio.h>

int main(void) {
	int n, k;
	while (~scanf("%d %d", &n, &k)) {
		int i, j;
		for (i=1; i<=n; i++) {
			for (j=1; j<=n; j++) {
				if (i == j)
					printf("%d", k);
				else
					printf("0");
				j==n ? putchar('\n') : putchar(' ');
			}
		}
	}

	return 0;
}
