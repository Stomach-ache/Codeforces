/*************************************************************************
    > File Name: a.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年11月06日 星期四 00时32分06秒
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
bool vis[100050];

int main(void) {
  	int a, m;
	cin >> a >> m;
	a %= m;
	int cur = a;
	bool flag = false;
	memset(vis, false, sizeof(vis));
	while (true) {
	  	vis[cur] = true;
	  	if (cur % m == 0) {
		  	flag = true;
			break;
		}
		cur = cur + cur % m;
		cur %= m;
		if (vis[cur]) break;
	}
	if (flag) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}
