#include <stdio.h>

#define mod 1000000007

typedef long long ll;
ll n, x, a[100005], b[100005];

/* 快速幂 */
ll pow_mod(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b%2) 
			res = (res*a)%mod;
		b /= 2;
		a = (a*a)%mod;
	}

	return res;
}

int main(void) {
	while (~scanf("%lld %lld", &n, &x)) {
		ll i, sum = 0;
		for (i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
			sum += a[i];
		}
		for (i = 1; i <= n; i++)
			b[i] = sum - a[n-i+1];

		ll ans = b[1], cnt = 0, beg = 0;
		while (1) {
			ll cnt2 = 0;
			for (i=beg+1; i<=n; i++) {
				if (ans == b[i])
					cnt2++;
			}
			cnt += cnt2;
			if (cnt % x != 0)
				break;
			beg += cnt2;
			ans++;
			cnt /= x;
		}

		if (ans > sum)
			ans = sum;

		printf("%lld\n", pow_mod(x, ans));
	}

	return 0;
}
