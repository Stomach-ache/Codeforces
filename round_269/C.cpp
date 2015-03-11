/*************************************************************************
    > File Name: C.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年09月27日 星期六 00时13分45秒
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
/*Let's fight!!!*/
#include <cstdio>

typedef long long ll;

ll n;

int main() {

  	scanf("%lld", &n);
	ll s = 2;
	ll ans = 0;
	for (int i = 1; ; i++) {

		if (s > n) break;
		if ((n - s) % 3 == 0) ans++;
		s = s + i * 3 + 2;
	}
	printf("%lld\n", ans);
	return 0;
}
