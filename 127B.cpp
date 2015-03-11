/*************************************************************************
    > File Name: 127B.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年07月18日 星期五 21时32分25秒
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

int n;
int vis[105];
int
main(void) {
  	while (~scanf("%d", &n)) {
	  	memset(vis, 0, sizeof(vis));
	  	for (int i = 0; i < n; i++) {
		  	int a;
			scanf("%d", &a);
			vis[a]++;
		}
		int ans = 0, tmp = 0;
		for (int i = 1; i <= 100; i++) {
		  	ans += vis[i] / 4;
			if (vis[i] % 4 >= 2) {
			  	if (tmp == 1) ans++, tmp = 0;
				else tmp = 1;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}
