#include <stdio.h>
#include <string.h>

typedef long long ll;
ll a[10];
char b[4], tmp[10];

#define min(x,y) ((x)<(y)?(x):(y))

int main(void) {
	while (~scanf("%lld %lld %lld %lld\n", &a[0], &a[1], &a[2], &a[3])) {
		gets(tmp);
		b[0] = tmp[0];
		b[1] = tmp[2];
		b[2] = tmp[4];
		int i, j, k, q, m;
		ll ans = -1;
		for (i=0; i<4; i++)
			for (j=i+1; j<4; j++) {
				if (b[0] == '+')
					a[4] = a[i]+a[j];
				else
					a[4] = a[i]*a[j];
				for (k=0; k<5; k++) {
					if (k==i || k==j)
						continue;
					for (q=k+1; q<5; q++) {
						if (q==i || q==j)
							continue;
						if (b[1] == '+')
							a[6] = a[k]+a[q];
						else
							a[6] = a[k]*a[q];
						for (m=0; m<5; m++) {
							if (m!=i && m!=j && m!=k && m!=q) {
                                ll tt;
				if (b[2] == '+')
					tt = a[m]+a[6];
				else
					tt = a[m]*a[6];
				if (ans == -1)
					ans = tt;
				else
					ans = min(ans, tt);
							}
						}
					}
				}
			}
		printf("%lld\n", ans);
	}

	return 0;
}
