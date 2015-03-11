/*************************************************************************
    > File Name: D.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年07月18日 星期五 15时32分49秒
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

typedef long long LL;

LL
min(LL x, LL y) {
  	return x < y ? x : y;
}

int
main(void) {
  	LL n, m, k;
  	while (~scanf("%I64d %I64d %I64d", &n, &m, &k)) {
	  	LL left = 1, right = n * m;
		while (left < right) {
		  	LL mid = (left + right) >> 1;
			LL cnt = 0;
			for (LL i = 1; i <= n; i++) {
			  	cnt += min(m, mid/i);
			}
			if (cnt < k) left = mid + 1;
			else right = mid;
		}
		printf("%I64d\n", right);
	}

	return 0;
}
