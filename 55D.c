/*
   unsolve
*/
#include <stdio.h>
#include <string.h>

typedef long long ll;

ll dp[20][3000], digit[20], ten[20];

void init() {

	memset(dp, -1, sizeof(dp));

	ten[0] = 1;
	int i;
	for (i=1; i<20; i++)
		ten[i] = ten[i-1]*10;

	return ;
}

int gcd(int a, int b) {
	if (!b)
		return a;
	return gcd(b, a%b);
}

ll dfs(int pos, ll val, int have[], int doing) {
	int i, lcm, tmp = 2520, tmp2 = 1, cnt = 0;
	for (i=2; i<=9; i++) {
		if (have[i]) {
			tmp = gcd(tmp, i);
			tmp2 *= i;
			cnt++;
		}
	}
	if (cnt == 0)
		lcm = 0;
	else if (cnt == 1)
		lcm = tmp2;
	else
		lcm = tmp2/tmp;

	int mod = lcm==0 ? 0 : val%lcm;

	/* if (pos==-1 && mod==0) */
		/* printf("%lld\n", val); */
	if (pos == -1)
		return mod == 0;
	/* if (!doing && dp[pos][mod]!=-1) */
		/* return dp[pos][mod]; */

	int end = doing ? digit[pos] : 9;
	ll ans = 0;
	for (i=0; i<=end; i++) {
		if (!have[i]) {
			have[i] = 1;
			ans += dfs(pos-1, val+i*ten[pos], have, i==end && doing);
			have[i] = 0;
		}
		else
			ans += dfs(pos-1, val+i*ten[pos], have, i==end && doing);
	}

	if (!doing)
		dp[pos][mod] = ans;

	return ans;
}

ll solve(ll n) {
	int len = 0;
	while (n) {
		digit[len++] = n%10;
		n /= 10;
	}

	int have[10];
	memset(have, 0, sizeof(have));

	return dfs(len-1, 0, have, 1);
}

int main(void) {
	init();
	int t;
	scanf("%d", &t);
	while (t--) {

		ll li, ri;
		scanf("%lld %lld", &li, &ri);
		printf("%lld\n", solve(ri) - solve(li-1));
	}

	return 0;
}
