/*************************************************************************
    > File Name: A.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年08月08日 星期五 23时32分05秒
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
typedef pair<int, int> pii;
const int maxn = 100002;
#define x first
#define y second
pii a[maxn];
int n;
bool vis[maxn];

int main(void) {
  	while (~scanf("%d", &n)) {
	  	for (int i = 0; i < n; i++) 
		  	scanf("%d %d", &a[i].x, &a[i].y);
		sort(a, a + n);
		bool flag = false;
		memset(vis, false, sizeof(vis));
		for (int i = 1; i < n; i++) {
		  	if (a[i].y < a[i-1].y) {
			  	flag = true;
				break;
			}
		}
		if (flag) puts("Happy Alex");
		else puts("Poor Alex");
	}
	return 0;
}
