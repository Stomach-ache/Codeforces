#include <stdio.h>
#define min(x,y) ((x)<(y)?(x):(y))
#define inf 0x3f3f3f3f

int neg[100005], zr[100005], t[100005],  n;

int main(void) {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	while (~scanf("%d", &n)) {
		int i;
		neg[0] = zr[0] = 0;
		for (i=1; i<=n; i++) {
			scanf("%d", &t[i]);
			neg[i] = neg[i-1];
			zr[i] = zr[i-1];
			if (t[i] < 0) 
				neg[i]++;
			else if (t[i] == 0)
				zr[i]++;
		}
		int tot = neg[n]+zr[n];
		int ans = inf;
		for (i=1; i<n; i++) {
			ans = min(ans, i-neg[i] + tot-neg[i]-zr[i]);
		}

		printf("%d\n", ans);
	}

	return 0;
}
