/*************************************************************************
    > File Name: c.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年11月06日 星期四 00时50分45秒
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

int main(void) {
	int n;
	cin >> n;
	while (n--) {
	  	LL a, b, res = 0LL;
		cin >> a >> b;
		int i, cnt = 0;
		for (i = 60; i >= 0; i--) {
		  	if ((a & (1LL<<i)) == (b & (1LL<<i))) {
				if ((a&(1LL<<i)) != 0) {
					res += (1LL<<i);
					cnt++;
				}
			}
			else break;
		}
		i--;
		while (i >= 0) {
		  	cnt++;
			res += (1LL<<i);
			i--;
		}
		int lcnt = 0, rcnt = 0;
		for (i = 60; i >= 0; i--) if (a & (1LL<<i)) lcnt++;
		for (i = 60; i >= 0; i--) if (b & (1LL<<i)) rcnt++;
		if (lcnt > cnt) {
		  	cnt = lcnt; 
			res = a;
		} else if (lcnt == cnt) {
		  	res = a;
		}
		if (rcnt > cnt) res = b;
		cout << res << endl;
	}

	return 0;
}
