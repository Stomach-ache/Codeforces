/*************************************************************************
    > File Name: 436C.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年06月24日 星期二 17时03分36秒
    > Propose: 
 ************************************************************************/

#include <cmath>
#include <string>
#include <cstdio>
#include <vector>
#include <fstream>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define INF (0x3f3f3f3f)
int n, m, k, w;
char a[1002][12][12];
int cost[1002][1002], d[1002], from[1002];
bool used[1002];
vector<int> OoO;

int
dist(int x, int y) {
  	int cnt = 0;
  	for (int i = 0; i < n; i++) 
	  	for (int j = 0; j < m; j++)
		  	if (a[x][i][j] != a[y][i][j]) cnt++;
	return cnt;
}

int
main(void) {
  	ios_base::sync_with_stdio(false);
  	while (~scanf("%d %d %d %d", &n, &m, &k, &w)) {
	  	for (int i = 1; i <= k; i++)
		  	for (int j = 0; j < n; j++) scanf("%s", a[i][j]);
		
		for (int i = 1; i <= k; i++) {
		  	for (int j = i+1; j <= k; j++) {
			  	cost[i][j] = cost[j][i] = dist(i, j) * w;
			}
			cost[i][0] = cost[0][i] = m * n;
		}
		memset(used, false, sizeof(used));
		memset(d, 0x3f, sizeof(d));
		d[0] = 0;
		int ans = 0;
		OoO.clear();
		while (true) {
		  	int v = -1;
			for (int u = 0; u <= k; u++) {
			  	if (!used[u] && (v==-1 || d[v] > d[u])) {
				  	v = u;
				}
			}
			if (v == -1) break;
			used[v] = true;
			ans += d[v];
			for (int u = 0; u <= k; u++) if (!used[u] && d[u] > cost[u][v]){
			  	d[u] = cost[u][v];
				from[u] = v;
			}
			OoO.push_back(v);
		}
		printf("%d\n", ans);
		for (int i = 1; i <= k; i++) {
		  	printf("%d %d\n", OoO[i], from[OoO[i]]);
		}
	}

	return 0;
}
