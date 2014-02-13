#include <stdio.h>
#include <string.h>

#define max(x,y) ((x)>(y)?(x):(y))
int n, a[100005], s[100005];

int main(void) {
	while (~scanf("%d", &n)) {
		int i;
		for (i=1; i<=n; i++)
			scanf("%d", &a[i]);
		s[1] = 1; s[2] = 2;
		for (i=3; i<=n; i++) {
			if (a[i] == a[i-2]+a[i-1])
				s[i] = s[i-1]+1;
			else
				s[i] = 2;
		}
		int ans = 0;
		for (i=1; i<=n; i++)
			ans = max(ans, s[i]);

		printf("%d\n", ans);
	}

	return 0;
}
