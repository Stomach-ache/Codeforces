#include <stdio.h>

#define inf 1e-6

int n, p[3005];

int solve(int cnt){
	if (cnt == 0)
		return 0;

	if (cnt == 1)
		return 1;

	int res = 4+solve(cnt-2);

	return res;
}

int main(void){
	while (~scanf("%d", &n)) {
		int i, j;
		for (i=1; i<=n; i++) {
			scanf("%d", &p[i]);
		}
		int cnt = 0;
		for (i=1; i<n; i++) {
			for (j=i+1; j<=n; j++) {
				if (p[j] < p[i]){
					cnt++;
				}
			}
		}
		printf("%d.000000\n", solve(cnt));
	}

	return 0;
}
