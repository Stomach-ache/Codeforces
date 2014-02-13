#include <stdio.h>
#include <string.h>

#define max(x, y) ((x)>(y)?(x):(y))

int n, a[100005], sum2[100005], sum[100005];
char s[100005];

int solve(){
	int i, res = 0;
	for (i=0; i<n; i++) {
		if (s[i] == '1')
			res += a[i];
	}

	int ans = res;
	for (i=0; i<n; i++) {
		if (s[i] == '1')
			ans = max(ans, res-sum2[i]+sum[i]-a[i]);
	}

	return ans;
}

int main(void){
	while (~scanf("%d", &n)) {
		int i;
		for (i=0; i<n; i++) {
			scanf("%d", &a[i]);
			if (i == 0)
				sum[i] = a[i];
			else
				sum[i] = sum[i-1]+a[i];
		}
		scanf("%s", s);
		for (i=0; i<n; i++) {
			if (i == 0)
				sum2[i] = 0;
			else
				sum2[i] = sum2[i-1];
			if (s[i] == '1')
				sum2[i] += a[i];
		}

		printf("%d\n", solve());
	}

	return 0;
}
