/*************************************************************************
    > File Name: B.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年10月06日 星期一 23时37分34秒
    > Propose: 
 ************************************************************************/
#include <map>
#include <cmath>
#include <string>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
/*Let's fight!!!*/

int ans[1000050];
int main(void) {
  	ios::sync_with_stdio(false);
  	int n, pre = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
	  	int x;
		cin >> x;
		for (int j = pre; j < pre + x; j++) {
		  	ans[j] = i;
		}
		pre = pre + x;
	}
	int m;
	cin >> m;
	while (m--) {
	  	int x;
		cin >> x;
		cout << ans[x] << endl;
	}
	return 0;
}
