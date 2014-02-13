/*************************************************************************
    > File Name: 235A.c
    > Author: Stomach_ache
    > Mail: 1179998621@qq.com 
    > Created Time: 2014年01月08日 星期三 12时43分12秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/* please do not use the %lld specificator to read or write
   64-bit intergers in C++. It is preferred to use cin, cout
   streams or the %I64d specificator. */
typedef long long LL;
#define max(x,y) ( (x) > (y) ? (x) : (y) )

LL gcd(LL a, LL b) {
		return !b ? a : gcd(b, a%b);
}

int main(void) {
		int n;
		while ( ~scanf("%d", &n) ) {
				if ( n == 1 )
						puts("1");
				else if ( n == 2 )
						puts("2");
				else if ( n % 2 )
						printf("%lld\n", (LL)n * (n-1) * (n-2));
				else {
						LL ans = (LL)(n-1) * (n-2) * (n-3);
						LL tmp = (LL)n * (n-1);
						LL i;
						for ( i = n-2; tmp*i > ans; i--) {
								ans = max( ans, tmp / gcd(tmp, i) * i );
						}
						printf("%lld\n", ans);
				}
		}

		return 0;
}
