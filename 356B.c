#include <stdio.h>
#include <string.h>

typedef long long ll;

ll n, m;
char x[1000005], y[1000005];

ll gcd(ll a, ll b){
	while (b) {
		ll tmp = a;
		a = b;
		b = tmp%b;
	}

	return a;
}

int main(void){
	while (~scanf("%lld %lld", &n, &m)) {
		scanf("%s", x);
		scanf("%s", y);
		ll len, len2;
		len = strlen(x);
		len2 = strlen(y);
		ll lcm = len*len2/gcd(len, len2);
		ll ans = 0, i, cnt;
		cnt = n*len/lcm;
		for (i=0; i<lcm; i++) {
			if (x[i%len] != y[i%len2])
				ans++;
		}
		printf("%lld\n", ans*cnt);
	}

	return 0;
}
