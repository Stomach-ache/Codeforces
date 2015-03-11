/*************************************************************************
    > File Name: E.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年08月09日 星期六 08时16分23秒
    > Propose: 
 ************************************************************************/

#include <cmath>
#include <string>
#include <vector>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 300002;
int n, m, q;
int d[maxn], p[maxn], rank[maxn];
int x, w, best;
vector<int> g[maxn];

int getFa(int x) {
  	return x != p[x] ? p[x] = getFa(p[x]) : x;
}

void dfs(int u, int fa, int high) {
	p[u] = x;
	if (high > best) best = high, w = u;
	for (int i = 0; i < (int)g[u].size(); i++) if (g[u][i] != fa) 
	  	dfs(g[u][i], u, high + 1);
}

void unite(int x, int y) {
	if (x == y) return ;
	if (rank[x] >= rank[y]) {
	  	p[y] = x;
		d[x] = max(max(d[x], d[y]), (d[x]+1)/2+(d[y]+1)/2+1);
		if (rank[x] == rank[y]) rank[x]++;
	} else {
	  	p[x] = y;
		d[y] = max(max(d[x], d[y]), (d[x]+1)/2+(d[y]+1)/2+1);
	} 
}

int main(void) {
  	scanf("%d %d %d", &n, &m, &q);
	for (int i = 0; i < m; i++) {
	  	int from, to;
		scanf("%d %d", &from, &to);
		g[from].push_back(to);
		g[to].push_back(from);
	}
	for (x = 1; x <= n; x++) if (!p[x]) {
	  	best = -1; dfs(x, 0, 0);
		best = -1, dfs(w, 0, 0);
		d[x] = best;
	}
	while (q--) {
	  	int t;
		scanf("%d %d", &t, &x);
		if (t == 1) {
			printf("%d\n", d[getFa(x)]);
		} else {
		  	int y;
			scanf("%d", &y);
			unite(getFa(x), getFa(y));
		}
	}
	return 0;
}
