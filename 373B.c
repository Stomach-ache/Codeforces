/*************************************************************************
    > File Name: 373B.c
    > Author: Stomach_ache
    > Mail: 1179998621@qq.com 
    > Created Time: 2013年12月14日 星期六 13时07分07秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef long long ll;

ll w, m, k, s, cnt[20], pow_10[20];

void init() {
	cnt[1] = 9;
	pow_10[0] = 1;
	int i;
	for (i = 2; i <= 18; i++)
		cnt[i] = cnt[i-1] * 10;
	for (i = 1; i <= 18; i++)
		pow_10[i] = pow_10[i-1] * 10;
}

int ok(ll n) {
	ll tmp = pow_10[s] - m, sum, i;
	if (n <= tmp)
		return w / (s * k) >= n;
	else {
		ll ww = w;
		sum = tmp, i = s + 1;
		ww -= tmp * s * k;
		while (ww) {
			if (sum >= n)
				return 1;

			if (ww / (i * k) < cnt[i])
				break;

			ww -= cnt[i] * i * k;
			sum += cnt[i];
			i++;
		}
		if (ww) 
			sum += ww / (i * k);
	}

	return sum >= n;
}

ll solve() {
	s = (int)log10(m+0.0) + 1;
	/* printf("s = %lld\n", s); */

	ll lf = 0, rgt = 10000000000000000, res = 0;

	while (lf <= rgt) {
		ll mid = (lf + rgt) >> 1;

		if (ok(mid)) {
			res = mid;
			lf = mid + 1;
		}
		else
			rgt = mid - 1;
	}

	return res;
}

int main(void) {
	init();

	while (~scanf("%lld %lld %lld", &w, &m, &k)) {

		ll ans = solve();
		printf("%lld\n", ans);
	}

	return 0;
}
