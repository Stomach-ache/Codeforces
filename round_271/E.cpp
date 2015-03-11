/*************************************************************************
    > File Name: E.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年10月07日 星期二 14时02分05秒
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

const int MAX_N = 100005;
#define lson(x) (x<<1)
#define rson(x) ((x<<1) | 1)
typedef pair<int, int> pii;
typedef long long LL;
int pre[MAX_N];
LL h[MAX_N];

struct node {
  	int l, r, ans, id; 
}tr[MAX_N*3];

void pushup(int rt) {
  	if (tr[lson(rt)].ans > tr[rson(rt)].ans) {
	  	tr[rt].ans = tr[lson(rt)].ans;
	  	tr[rt].id= tr[lson(rt)].id;
	} else {
	  	tr[rt].ans = tr[rson(rt)].ans;
	  	tr[rt].id= tr[rson(rt)].id;
	}
}

void build(int rt, int l, int r) {
  	tr[rt].l = l, tr[rt].r = r;
	if (l == r) {
	  	tr[rt].ans = 0;
		tr[rt].id = l;
		return ;
	}
	int mid = (l + r) >> 1;
	build(lson(rt), l, mid);
	build(rson(rt), mid + 1, r);
	pushup(rt);
}

void update(int rt, int pos, int val) {
  	if (tr[rt].l == pos && tr[rt].r == pos) {
	  	tr[rt].ans = max(tr[rt].ans, val);
		return ;
	}
	int mid = tr[lson(rt)].r;
	if (pos <= mid) update(lson(rt), pos, val);
	else update(rson(rt), pos, val);
	pushup(rt);
}

pii query(int rt, int l, int r) {
  	if (tr[rt].l >= l && tr[rt].r <= r) {
	  	return pii(tr[rt].ans, tr[rt].id);
	}
	int mid = tr[lson(rt)].r;
	pii res; 
	res.first = -1, res.second = 1;
	if (l <= mid) {
	  	pii tmp = query(lson(rt), l, r);
	  	if (res.first < tmp.first) {
		  	res = tmp;
		}
	}
	if (r > mid) {
	  	pii tmp = query(rson(rt), l, r);
	  	if (res.first < tmp.first) {
		  	res = tmp;
		}
	}
	return res;
}

void gao(int u) {
  	if (u == 0) return ;
	gao(pre[u]);
	cout << u << ' ';
}

int id[MAX_N];
vector<LL> arr;
int main(void) {
  	ios::sync_with_stdio(false);
  	int n, d;
  	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
	  	cin >> h[i];
		arr.push_back(h[i]);
	}
	sort(arr.begin(), arr.end());
	arr.resize(unique(arr.begin(), arr.end()) - arr.begin());
	int w = (int)arr.size();
	build(1, 1, w);

	for (int i = 1; i <= n; i++) {
	  	int lft = upper_bound(arr.begin(), arr.end(), h[i] - d) - arr.begin() + 1;
		int rgt = lower_bound(arr.begin(), arr.end(), h[i] + d) - arr.begin() + 1;
		pii ans = make_pair(0, 1);
		if (lft - 1 >= 1) ans = max(ans, query(1, 1, lft - 1)); 
		if (rgt <= w) ans = max(ans, query(1, rgt, w));
		int pos = lower_bound(arr.begin(), arr.end(), h[i]) - arr.begin() + 1;
		update(1, pos, ans.first + 1);
		pre[i] = id[ans.second];
		id[pos] = i;
	}
	pii t = query(1, 1, w);
	cout << t.first << endl;
	gao(pre[id[t.second]]);
	cout << id[t.second] << endl;

	return 0;
}
