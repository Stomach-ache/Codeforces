#include <stdio.h>

typedef long long ll;

ll gcd(ll a, ll b, ll &d, ll &x, ll &y)
{
	if (!b)
	{
		d = a; x = 1; y = 0;
	}
	else
	{
		gcd(b, a%b, d, y, x);
		y -= x * (a/b);
	}
}

int main(void)
{
	ll a, b, c, d, x, y;

	while (~scanf("%I64d %I64d %I64d", &a, &b, &c))
	{
		gcd(a, b, d, x, y);

		if (c % d)
			puts("-1");
		else 
				printf("%I64d %I64d\n", x * (-c/d), y * (-c/d));	
	}

	return 0;
}
