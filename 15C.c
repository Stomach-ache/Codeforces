#include <stdio.h>

typedef long long ll;

ll func(ll x){
	ll res;
	if (x%4 == 0)
		res = x;
	else if (x%4 == 1)
		res = 1;
	else if (x%4 == 2)
		res = x+1;
	else
		res = 0;

	return res;
}

int main(void){
	int n;
	while (~scanf("%d", &n)) {
		ll x, m, i, ans = 0;
		for (i=0; i<n; i++) {
			scanf("%lld %lld", &x, &m);
			ll tmp = func(x+m-1)^func(x-1);
			ans ^= tmp;
		}
		if (ans != 0) {
			puts("tolik");
		}
		else {
			puts("bolik");
		}
	}

	return 0;
}
