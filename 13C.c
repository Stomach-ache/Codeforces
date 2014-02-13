#include <stdio.h>
#include <string.h>
#define min(x,y) ((x)<(y)?(x):(y))
#define inf 0x3f3f3f3f
typedef long long ll;
int n, a[5005], dp[5005];

ll solve(int pre, int pos) {
	if (pos == n)
		return a[n]>=pre ? 0 : pre-a[n];

	if (dp[pos] != -1)
		return dp[pos];
	ll res = inf;
	if (a[pos] < pre) {
		return solve(pre, pos+1)+pre-a[pos];
	}
	int i;
	for (i=a[pos]; i>=pre; i--) {
		res = min(res, solve(i, pos+1)+a[pos]-i);
	}

	return dp[pos]=res;
}

int main(void) {
	while (~scanf("%d", &n)) {
		memset(dp, -1, sizeof(dp));
		int i, ans = 0;// m = inf;
		for (i=1; i<=n; i++) {
			scanf("%d", &a[i]);
//			m = min(m, a[i]);
		}

//		printf("%lld\n", solve(m, 1));
	}

	return 0;
}
