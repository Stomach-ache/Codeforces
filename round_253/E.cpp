/*************************************************************************
    > File Name: E.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年06月23日 星期一 22时48分29秒
    > Propose: 
 ************************************************************************/

#include <cmath>
#include <string>
#include <vector>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define min(x, y) ((x) < (y) ? (x) : (y))
typedef long long LL;
int n, a[500005];
int b[500005];

int
main(void) {
  	while (~scanf("%d", &n) && n) {
	  	for (int i = 1; i <= n; i++) {
		  	scanf("%d", a + i);
		}
	  	if (n <= 2) {
		  	puts("0"); continue;
		}
		LL  ans = 0;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
		  	b[cnt++] = a[i];
		  	while (cnt > 2 && b[cnt-2] <= b[cnt-1] && b[cnt-2] <= b[cnt-3]) {
			  	ans += min(b[cnt-1], b[cnt-3]);
				b[cnt-2] = b[cnt-1];
				cnt--;
			}
		}	
		for (int i = 1; i < cnt-1; i++) {
		  	ans += min(b[i-1], b[i+1]);
		}
		printf("%I64d\n", ans);
	}

	return 0;
}
