/*************************************************************************
    > File Name: B.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com 
    > Created Time: 2014年12月30日 星期二 23时16分29秒
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

const int MAX_N = 301;

char a[MAX_N][MAX_N];
int n;
bool d[MAX_N][MAX_N], vis[MAX_N];
int pos[MAX_N], p[MAX_N];

int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", p + i);
		pos[p[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%s", a[i] + 1);
	}
	for (int i = 1; i <= n; i++) a[i][i] = '1';

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (a[i][k] == '1' && a[k][j] == '1') {
					a[i][j] = a[j][i] = '1';
				}
			}
		}
	}
	memset(vis, false, sizeof(vis));
	for (int i = 1; i <= n; i++) {

			for (int j = 1; j <= n; j++) if (!vis[j] && '1' == a[pos[j]][i]) {
				vis[j] = true;
				printf("%d", j);
				break;
			}
		if (i < n) putchar(' ');
		else puts("");
	}
	return 0;
}
