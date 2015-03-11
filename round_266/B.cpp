/*************************************************************************
    > File Name: B.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年09月13日 星期六 00时15分07秒
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
LL solve(LL &a, LL &b, LL c) {
  	if (a % 6 == 0 || b % 6 == 0) return -1;
	if (a * b >= c) return a * b;
	if (a * b + a >= c && a * b + b >= c) {
	  	if (a*b+a < a*b+b) {
		  	b++;
			return a * b;
		} else {
		  	a++;
			return a * b;
		}
	}
	if (a * b + a >= c) {
	  	LL tmp = a * b + a;
		LL res = solve(++a, b, c);
		if (res < tmp) return res;
		else {
		  	a--;
			return tmp;
		}
	}
	if (a * b + b >= c) {
	  	LL tmp = a * b + b;
	  	LL res = solve(a, ++b, c);
		if (res < tmp) {
		  	return res;
		} else {
		  	b--;
			return tmp;
		}
	}
	return min(solve((++a), b, c), solve(a, ++b, c));
}

typedef long long LL;
int main(void) {
  	LL n, a, b, s, a1, b1;
	cin >> n >> a >> b;
	if (a * b >= 6 * n) {
	  	cout << a * b << endl << a << ' ' << b << endl;
		return 0;
	}

	a1 = a, b1 = b;
	int res = solve(a1, b1, 6 * n);
	if (res != -1) {
	  	cout << res << endl << a1 << ' ' << b1 << endl;
		return 0;
	}

	LL lfta = 6 - a % 6, lftb = 6 - b % 6;
	if ((a + lfta) * b <= (b + lftb) * a) {
	  	cout << 6 * n << endl << a + lfta << ' ' << b << endl;
	} else {
	  	cout << 6 * n << endl << a << ' ' << b + lftb << endl;
	}
	return 0;
}
