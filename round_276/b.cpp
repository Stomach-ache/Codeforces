/*************************************************************************
    > File Name: b.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年11月06日 星期四 00时37分30秒
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
const LL INF = (LL)1e12;

int main(void) {
  	LL n, xmin = INF, xmax = -INF, ymin = INF, ymax = -INF;
	cin >> n;
	for (int i = 0; i < n; i++) {
	  	LL x, y;
		cin >> x >> y;
		xmin = min(x, xmin);
		xmax = max(x, xmax);
		ymin = min(y, ymin);
		ymax = max(y, ymax);
	}
	if (xmax - xmin == ymax - ymin) {
	  	cout << (ymax - ymin) * (ymax - ymin) << endl;
	} else {
	  	LL tmp = max(xmax - xmin, ymax - ymin);	
	  	cout << tmp * tmp << endl;
	}
	return 0;
}
