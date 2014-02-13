#include <stdio.h>

int main(void) {
	int n, k;
	while (~scanf("%d %d", &n, &k)) {
		int i = 1, f = k;
		while (k > 0) {
			printf("%d %d %d %d", i, i+1, i+3, i+2);
			i = i+4;
			k--;
			if (k)
				putchar(' ');
		}
		for (; i<=2*n-1; i+=2) {
			if (i != 1)
				putchar(' ');
			printf("%d %d", i, i+1);
		}
		puts("");
	}

	return 0;
}
