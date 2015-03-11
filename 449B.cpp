/*************************************************************************
    > File Name: 449B.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年07月20日 星期日 10时17分44秒
    > Propose: 
 ************************************************************************/
#include <queue>
#include <cmath>
#include <vector>
#include <string>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define X first
#define Y second
const int maxn = 100005;
typedef long long LL;
typedef pair<LL, int> pii;
LL d[maxn];
int n, m, k;
bool done[maxn];
vector<pii> G[maxn];

void
dijkstra() {
  	priority_queue<pii> q;
	d[0] = 0;
	for (int i = 0; i < n; i++) if (d[i] != 1e15) q.push(pii(-d[i], i));
	//memset(done, false, sizeof(done));
	while (!q.empty()) {
	  	pii cur = q.top();
		q.pop();
		int r = -cur.X;
		int u = cur.Y;
		if (r != d[u]) continue;
		for (unsigned i = 0; i < G[u].size(); i++) {
		  	int v = G[u][i].X;
			if (d[v] > d[u] + G[u][i].Y) {
			  	d[v] = d[u] + G[u][i].Y;
				q.push(pii(-d[v], v));
			}
		}
	}

	return ;
}

int
main(void) {
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
	  	int u, v, x;
		cin >> u >> v >> x;
		u--, v--;
		G[u].push_back(pii(v, x));
		G[v].push_back(pii(u, x));
	}
	for (int i = 0; i < n; i++) d[i] = 1e15;
	for (int i = 0; i < k; i++) {
	  	int s, y;
		cin >> s >> y;
		s--;
		d[s] = min(d[s], y*1LL);
	}
	dijkstra();

	int res = 0;
	for (int i = 1; i < n; i++) {
	  	int t = 1;
	  	for (unsigned j = 0; j < G[i].size(); j++) {
		  	if (d[i] == d[G[i][j].X] + G[i][j].Y) {
			  	t = 0;
				break;
			}
		}
		res += t;
	}
	cout << k - res << endl;

	return 0;
}
