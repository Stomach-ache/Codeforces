#include <stdio.h>
#include <stdlib.h>
#define min(x,y) ((x)<(y)?(x):(y))

int n, m, a, b[100005], p[100005];

int cmp(const void *x, const void *y) {
	return *(int*)x - *(int*)y;
}

int solve(int x) {
	int i, j, cnt = 0, left = a;
	i = n, j = x;
	while (i>=1 && j>=1) {
		if (b[i] >= p[j]) {
			cnt++;
			j--;
		}
		else if (b[i]+left >= p[j]) {
			cnt++;
			left -= p[j]-b[i];
			j--;
		}
		i--;
	}

	return cnt == x;
}

int main(void) {
	while (~scanf("%d %d %d", &n, &m, &a)) {
		int i;
		for (i=1; i<=n; i++)
			scanf("%d", &b[i]);
		for (i=1; i<=m; i++)
			scanf("%d", &p[i]);

		qsort(b+1, n, sizeof(int), cmp);
		qsort(p+1, m, sizeof(int), cmp);

		int L = 0, R = min(n,m), r = 0;
		while (L <= R) {
			int mid = L+(R-L)/2;
			if (solve(mid)) {
				r = mid;
				L = mid+1;
			}
			else
				R = mid-1;
		}
		int  s = 0;
		for (i=1; i<=r ;i++) {
			s += p[i];
		}
		if (s <= a)
			s = 0;
		else 
			s -= a;
		printf("%d %d\n", r, s);
	}

	return 0;
}
