/*************************************************************************
    > File Name: D.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年08月13日 星期三 14时10分37秒
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
/*Let's fight!!!*/

const int maxn = 100005;
int ch[maxn][30];

struct Trie {
	int sz;
	Trie() {
	  	memset(ch[0], 0, sizeof(ch[0]));
		sz = 1;
	}
	void insert(char *s);
	void dfs(int u);
};

inline void Trie::insert(char *s) {
  	int u = 0, n = (int)strlen(s);
	for (int i = 0; i < n; i++) {
	  	int id = s[i] - 'a';
		if (!ch[u][id]) {
		  	memset(ch[sz], 0, sizeof(ch[sz]));
		  	ch[u][id] = sz++;
		}
		u = ch[u][id];
	}
}

bool win[maxn], lose[maxn];
inline void Trie::dfs(int u) {
  	bool flag = false;
  	for (int i = 0; i < 30; i++) if (ch[u][i]) {
	  	flag = true;
	  	int v = ch[u][i];
	  	dfs(v);
		if (!win[v]) win[u] = true;
		if (!lose[v]) lose[u] = true; 
	}
	if (!flag) lose[u] = true;
}

char str[maxn];
int main(void) {
  	int n, k;
	Trie A;
	scanf("%d %d", &n, &k);
	while (n--) scanf("%s", str), A.insert(str);
	memset(win, false, sizeof(win));
	memset(lose, false, sizeof(lose));
	A.dfs(0);
	if ((win[0] && lose[0]) || (win[0] && k&1)) puts("First");
	else puts("Second");

	return 0;
}
