#include <cstdio>
#include <cstring>

int n, q;
char str[1000005];

int main() {
	while (~scanf("%d", &n) && n) {
		int sum = 0, count = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int k;
				scanf("%d", &k);
				if (i == j)
					sum ^= k;
			}
		}
		scanf("%d", &q);
		while (q--) {
			int c;
			scanf("%d", &c);
			if (c == 1 || c == 2) {
				int i;
				scanf("%d", &i);
				sum ^= 1;
			}
			else {
				if (sum) 
					str[count++] = '1';
				else
					str[count++] = '0';
			}
				//printf("%d\n", sum);
		}
		str[count] = '\0';
		puts(str);
	}

	return 0;
}