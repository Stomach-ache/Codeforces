/*************************************************************************
    > File Name: A.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年08月30日 星期六 16时19分33秒
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

int n, s, x, y;

int main(void) {
  	cin >> n >> s;
	int ans = -1;
	for (int i = 0; i < n; i++) {
	  	cin >> x >> y;
		if (x < s && y != 0) ans = max(ans, 100 - y);
		else if (x < s && y == 0) ans = max(ans, 0);
		else if (x == s && y == 0) ans = max(ans, 0);
	}
	cout << ans << endl;
	return 0;
}
