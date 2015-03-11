/*************************************************************************
    > File Name: L.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年09月11日 星期四 21时25分10秒
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

typedef long long LL;
const int MAX_N = 50005;
struct cow {
  	int w, s;
	friend bool operator < (const cow &x, const cow &y) {
	  	return x.w + x.s < y.w + y.s;
	}
}a[MAX_N];

int  main(void) {
  	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i].w >> a[i].s;
	sort(a, a + n);

	int res = -1000000000, sum = 0;
	for (int i = 0; i < n; i++) res = max(sum-a[i].s, res), sum += a[i].w;
	cout << res << endl;

	return 0;
}
