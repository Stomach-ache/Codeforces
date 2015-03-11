/*************************************************************************
    > File Name: 459E.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年08月16日 星期六 08时05分04秒
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
const int maxn = 300005;
const int inf = 0x3f3f3f3f;
typedef pair<int, int> pii;
int n, m, i, j, sz, ans, tmp, from, to, cost;
#define fi first
#define se second
struct Edge {
  	int u, v, w;
	//Edge():u(0), v(0), w(0){}
	friend bool operator < (const Edge &x, const Edge &y) {
	  	return x.w < y.w;
	}
}edges[maxn];
vector<pii> pre[maxn];

void read(int &res) {
  	res = 0;
  	char c = ' ';
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9') res = res * 10 + c - '0', c = getchar();
}

int main(void) {
  	read(n); read(m);
    for (i = 0; i < m; i++)
	  	read(edges[i].u), read(edges[i].v), read(edges[i].w);

	sort(edges, edges + m);
	for (i = 0; i < m; i++) {
	  	from = edges[i].u, to = edges[i].v, cost = edges[i].w;
		sz = pre[from].size();
		tmp = 0;
		for (j = 0; j < sz; j++) if (pre[from][j].fi < cost) {
		  	tmp = max(tmp, pre[from][j].se + 1);
		}
		if (!tmp) tmp = 1;
		pre[to].push_back(pii(cost, tmp));
	}

	ans = -1;
	for (i = 1; i <= n; i++) if ((sz = pre[i].size())){
	  	for (j = 0; j < sz; j++) 
		  	ans = max(ans, pre[i][j].se);
	}
	printf("%d\n", ans);

	return 0;
}
