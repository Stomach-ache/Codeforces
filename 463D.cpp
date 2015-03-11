/*************************************************************************
    > File Name: 463D.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年08月31日 星期日 22时02分01秒
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
/*Let's fight!!!*/

#define rep(i, n) for (int i = (0); i < (n); i++)
#define FOR(i, n) for (int i = (1); i <= (n); i++)
int n, k;
int a[5][1005], dp[1005], pos[5][1005];
vector<int> G[1005];
bool vis[1005];

bool check(int x, int y) {
  	rep (i, k) if (pos[i][x] > pos[i][y]) return false;
	return true;
}

void dfs(int u) {
  	if (vis[u]) return;
	vis[u] = true;
	int sz = (int)G[u].size();
	rep (i, sz) {
	  	int v = G[u][i];
		dfs(v);
		dp[u] = max(dp[u], dp[v]);
	}
	dp[u]++;
}
 
int main(void) {
	cin >> n >> k;
	int a;
	rep (i, k) rep(j, n) cin >> a, pos[i][a] = j;
	FOR (i, n) FOR (j, n) if (i != j && check(i, j)) G[i].push_back(j);
	
//	FOR (i, n) rep (j, G[i].size()) cerr << i << "-->" << G[i][j] << endl;

	memset(vis, false, sizeof(vis));
	FOR (i, n) if (!vis[i]) dfs(i);

	int ans = 0;
	FOR (i, n) ans = max(ans, dp[i]);
	cout << ans << endl;
	
	return 0;
}
