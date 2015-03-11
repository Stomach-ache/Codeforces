/*************************************************************************
    > File Name: D.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年09月19日 星期五 14时41分44秒
    > Propose: 
 ************************************************************************/
#include <map>
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

const int MAX_N = 100050;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;
typedef long long LL;

int V; // 顶点数
vector<int> G[MAX_N], rG[MAX_N], vs;
bool used[MAX_N];
int cmp[MAX_N];
//题目变量
map<string, int> HASH;
int n, m, ID[MAX_N], X[MAX_N], Y[MAX_N];
pii s[MAX_N], ss[MAX_N], dp[MAX_N];

void add_edge(int from, int to) {
  	G[from].push_back(to);
	rG[to].push_back(from);
}

void dfs(int v) {
  	used[v] = true;
	for (int i = 0; i < G[v].size(); i++) {
	  	if (!used[G[v][i]]) dfs(G[v][i]);
	}
	vs.push_back(v);
}

void rdfs(int v, int k) {
  	used[v] = true;
	cmp[v] = k;
	ss[k] = min(ss[k], s[v]);
	for (int i = 0; i < rG[v].size(); i++) {
	  	if (!used[rG[v][i]]) rdfs(rG[v][i], k);
	}
}

int scc() {
  	memset(used, false, sizeof(used));
	vs.clear();
	for (int v = 1; v <= V; v++) {
	  	if (!used[v]) dfs(v);
	}
	memset(used, false, sizeof(used));
	int k = 0;
	for (int i = vs.size() - 1; i >= 0; i--) {
	  	if (!used[vs[i]]) {
		  	ss[++k] = pii(INF, INF);
			rdfs(vs[i], k);
		}
	}
	return k;
}


int get(string &str) {
  	for (int i = 0;  i < str.size(); i++) {
	  	str[i] = tolower(str[i]);
	}
	if (HASH.find(str) == HASH.end()) {
	  	HASH[str] = ++V;
		s[V].second= str.size();
		for (int j = 0; j < s[V].second; j++) if (str[j] == 'r') s[V].first++;
	  	return V;
	} else {
		return HASH[str];
	}
}

void rebuild() {
  	for (int i = 1; i <= V; i++) G[i].clear();
	for (int i = 1; i <= m; i++) if (cmp[X[i]] != cmp[Y[i]]) 
	  	add_edge(cmp[X[i]], cmp[Y[i]]);
}

pii DFS(int u) {
  	if (used[u]) return dp[u];
	used[u] = true;
	dp[u] = ss[u];
	for (int i = 0; i < G[u].size(); i++) {
	  	dp[u] = min(dp[u], DFS(G[u][i]));
	}
	return dp[u];
}

int main(void) {
  	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
	  	string str;
		cin >> str;
		int id = get(str);
		ID[i] = id;
	}

	cin >> m;
	for (int i = 1; i <= m; i++) {
	  	string x, y;
		cin >> x >> y;
		int u = get(x), v = get(y);
		add_edge(u, v);
		X[i] = u, Y[i] = v;
	}

	int k = scc();
	rebuild();

	memset(used, false, sizeof(used));
	LL resr = 0, resl = 0;
	for (int i = 1; i <= n; i++) {
	  	int pos = cmp[ID[i]];
		DFS(pos);
		resr += dp[pos].first;
		resl += dp[pos].second;
	}

	cout << resr << ' ' << resl << endl;
	return 0;
}
