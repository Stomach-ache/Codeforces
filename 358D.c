#include <stdio.h>
#include <string.h>

#define max(x, y) ((x)>(y)?(x):(y))

int n, a[3005], b[3005], c[3005], dp[2][30005];

void read(int tmp[]){
	int i;
	for (i=1; i<=n; i++) {
		scanf("%d", &tmp[i]);
	}

	return ;
}

int solve(int pre, int cur){
	if (cur == n){
		return pre ? b[cur] : a[cur];
	}
	if (dp[pre][cur] != -1) {
		return dp[pre][cur];
	}

	int ans;
	if (pre) {
		ans = max(solve(1, cur+1)+b[cur], solve(0, cur+1)+c[cur]);
	}
	else {
		ans = max(solve(1, cur+1)+a[cur], solve(0, cur+1)+b[cur]);
	}

	return dp[pre][cur]=ans;
}

int main(void){
	while (~scanf("%d", &n)) {
		read(a);
		read(b);
		read(c);

		memset(dp, -1, sizeof(dp));

		printf("%d\n", solve(0, 1));
	}

	return 0;
}
