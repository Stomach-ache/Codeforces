/*************************************************************************
    > File Name: A.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com 
    > Created Time: 2014年12月30日 星期二 23时06分52秒
 ************************************************************************/

#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<cstdio>
#include<vector>
#include<string>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int a[30050], n, t;
bool vis[30050];
int main(void) {
	scanf("%d %d", &n, &t);
	for (int i = 1; i < n; i++) scanf("%d", a + i);
	bool flag = false;
	int now = 1;
	while (true) {
		vis[now] = true;
		now = now + a[now];
		if (now == t) {
			flag = true;
			break;
		}
		if (vis[now]) break;
	}
	if (flag) puts("YES");
	else puts("NO");
	return 0;
}
