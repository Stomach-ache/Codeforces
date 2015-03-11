/*************************************************************************
    > File Name: C.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年07月19日 星期六 21时23分17秒
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

long long n, m, k;

int
main(void) {
   cin >> n >> m >> k;
	if (n + m - 2 < k) {
	  	puts("-1");
		return 0;
	}
//	if (n < m) swap(n, m);
	long long ans = 0;
	if (k >= n) {
	  	ans = max(ans, m/(k-(n-1)+1));
	} else {
	  	ans = max(ans, n/(k+1)*m);	
	}
	if (k >= m) {
	  	ans = max(ans, n/(k-(m-1)+1));
	} else {
	  	ans = max(ans, m/(k+1)*n);
	}
	cout << ans << endl;

	return 0;
}
