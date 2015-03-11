/*************************************************************************
    > File Name: 113C.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年07月20日 星期日 13时34分53秒
    > Propose: 
 ************************************************************************/

#include <cmath>
#include <string>
#include <bitset>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1e8+1e8+1e8;
bitset<maxn> p;

int
main(void) {
  	int L, R;
  	scanf("%d %d\n", &L, &R);
	p.set();
	for (int i = 3; i*i <= R; i+=2) if (p[i]) for (int j = i*i; j <= R; j+=2*i) p[j] = false;
	int ans = 0;
	for (int i = 5; i <= R; i+=4) if (p[i] && i >= L) ans++;
	ans += (L <= 2 && R >= 2) ? 1 : 0;
	printf("%d\n", ans);

	return 0;
}
