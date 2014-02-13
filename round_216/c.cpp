/*************************************************************************
    > File Name: c.cpp
    > Author: Stomach_ache
    > Mail: 1179998621@qq.com 
    > Created Time: 2013年11月30日 星期六 00时19分32秒
 ************************************************************************/

#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<cstdio>
#include<fstream>
#include<vector>
using namespace std;
int n, res[100005], cnt;
struct Edge{
	int x, y, t;
	Edge(int xx, int yy, int tt):x(xx), y(yy), t(tt){}
};
vector<Edge> edge;
vector<int> next[100005];

void AddEdge(int x, int y, int t) {
	edge.push_back(Edge(x, y, t));
	next[x].push_back(edge.size()-1);
}

int solve(int u, int fa) {
	int tmp = 0, s = next[u].size();
	if (s == 0)
		return 0;
	for (int i=0; i<s; i++) {
		int tmp2 = 0;
		int v = edge[next[u][i]].y;
		int e = edge[next[u][i]].t;
		if (fa!=-1 && v==fa)
			continue;
		tmp2 = solve(v, u);
		if (!tmp2 && e==2) {
			tmp2 = 1;
			res[cnt++] = v;
		}
		tmp += tmp2;
	}

	return tmp;
}

int main() {
	while (~scanf("%d", &n)) {
		for (int i=1; i<=n; i++)
			next[i].clear();
		edge.clear();
		cnt = 0;

		for (int i=1; i<n; i++) {
			int x, y, t;
			scanf("%d %d %d", &x, &y, &t);
			AddEdge(x, y, t);
			AddEdge(y, x, t);
		}
		int ans = solve(1, -1);
		printf("%d\n", ans);
		for (int i=0; i<ans; i++)
			printf("%d%c", res[i], i==ans-1?'\n':' ');
	}

	return 0;
}
