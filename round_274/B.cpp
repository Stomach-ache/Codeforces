/*************************************************************************
    > File Name: B.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年10月19日 星期日 17时15分42秒
    > Propose: 
 ************************************************************************/
#include <set>
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
LL a[100050], n, l, x, y;
set<LL> S;

int main(void) {
  	ios::sync_with_stdio(false);
	cin >> n >> l >> x >> y;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		S.insert(a[i]);
	}
	int boy = 1, girl = 1;
	for (int i = 2; i <= n; i++) {
	  	if (S.find(a[i] - x) != S.end()) girl = 0;
		if (S.find(a[i] - y) != S.end()) boy = 0;
	}
	LL xx = x, yy = y;
	if (boy && girl) {
	  	LL diff = y - x;
		for (int i = 2; i <= n; i++) {
	  		if (S.find(a[i] - diff) != S.end()) {
			  	if (a[i] - y > 0) {
			  		xx = a[i] - y;
					boy = 0;
					break;
				}
				else if (a[i] + x < l) {
				  	xx = a[i] + x;
					boy = 0;
					break;
				}
			}
			if (S.find(a[i] - x - y) != S.end()) {
			  	xx = a[i] - y;
				boy = 0;
				break;
			}
		}
	}
	int res = boy + girl;
	cout << res << endl;
	if (boy) cout << yy << ' ';
	if (girl) cout << xx << ' ';
	if (res) cout << endl;
	return 0;
}
