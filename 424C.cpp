/*************************************************************************
    > File Name: 424C.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年04月28日 星期一 11时44分14秒
    > Propose: 
 ************************************************************************/

#include <cmath>
#include <string>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N (1000000+5)

int n, p[MAX_N], s[MAX_N];

int
main(void) {
		scanf("%d", &n);
		p[0] = 0;
		for (int i = 1; i <= n; i++) {
				scanf("%d", &p[i]);
				p[i] ^= p[i-1];
		}
		s[0] = 0;
		for (int i = 1; i <= n; i++) {
				s[i] = i ^ s[i-1];
		}
		int ans = p[n];
		for (int i = 2; i <= n; i++) {
				if ((n / i) % 2) {
						ans ^= s[i-1];
				}
				ans ^= s[n%i];
		}
		printf("%d\n", ans);

		return 0;
}
