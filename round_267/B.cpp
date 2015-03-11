/*************************************************************************
    > File Name: B.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年09月18日 星期四 23时35分58秒
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

int n, k, m, x[1005];

int main(void) {
  	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 1; i <= m+1; i++) cin >> x[i];
	int res = 0;
	for (int i = 1; i <= m; i++) {
	  	int cnt = 0;
		for (int j = 0; j <= 21; j++) 
		  	if ((x[i]&(1<<j)) != (x[m+1]&(1<<j))) cnt++;
		if (cnt <= k) res++;
	}
	cout << res << endl;
	return 0;
}
