#include <stdio.h>
#include <string.h>

char a[105][15];
int n, k;

int ok(char *b) {
	int len = strlen(b), i, c[10];
	memset(c, 0, sizeof(c));
	for (i=0; i<len; i++) 
		c[b[i]-'0'] = 1;

	for (i=0; i<=k; i++)
		if (!c[i])
			return 0;

	return 1;
}

int main(void) {
	while (~scanf("%d %d", &n, &k)) {
		int i, ans = 0;
		for (i=0; i<n; i++) {
			scanf("%s", a[i]);
			if (ok(a[i]))
				ans++;
		}

		printf("%d\n", ans);
	}

	return 0;
}
