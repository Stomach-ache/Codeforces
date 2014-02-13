/*************************************************************************
    > File Name: 300C.c
    > Author: Stomach_ache
    > Mail: 1179998621@qq.com 
    > Created Time: 2014年01月07日 星期二 17时32分26秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define mod 1000000007
typedef long long LL;
int a, b, n, c[1000005], rfact[1000005];

int ok(int x) {
		while (x > 0) {
				int tmp = x % 10;
				if (tmp != a && tmp != b)
					return 0;
				x /= 10;
		}

		return 1;
}

LL pow_mod(LL a, LL b, LL c) {
		LL res = 1;
		while (b) {
				if (b & 1)
					res = (res * a) % c;
				a = (a * a) % c;
				b >>= 1;
		}

		return res % c;
}

int main(void) {
		while (~scanf("%d %d %d", &a, &b, &n)) {
				int i, cur = a * n, d = b - a;
				LL cnt = ok(cur);
				c[0] = 1;
				for (i = 1; i <= n; i++) {
						rfact[i] = pow_mod(i, mod-2, mod);
						c[i] = (LL)c[i - 1] * (n - i + 1) % mod;
						c[i] = (LL)c[i] * rfact[i] % mod;
				}
				for (cur += d, i = 1; i < n; i++, cur += d) {
						if (ok(cur)) {
								cnt += c[i];
								cnt %= mod;
						}
				}
				cnt = (cnt + ok(b * n)) % mod;
				printf("%lld\n", cnt);
		}

		return 0;
}
