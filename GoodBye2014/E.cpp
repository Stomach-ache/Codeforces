/*************************************************************************
    > File Name: E.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com 
    > Created Time: 2015年01月01日 星期四 21时21分42秒
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

const int MAX_N = 200005;
typedef long long LL;
#define lson(x) (x<<1)
#define rson(x) ((x<<1) | 1)
struct Node {
	int l, r;
	LL mmax;
};

struct SegmentTree {
	Node tr[4*MAX_N];

	void build(int rt, int l, int r) {
		tr[rt].l = l; tr[rt].r = r;
		tr[rt].mmax = 0;
		if (l != r) {
			int mid = (l + r) >> 1;
			build(lson(rt), l, mid);
			build(rson(rt), mid + 1, r);
		}
	}

	void update(int rt, int l, int v) {
		if (tr[rt].l == l && tr[rt].r == l) {
			tr[rt].mmax = v;
		} else {
			int mid = tr[lson(rt)].r;
			if (l <= mid) update(lson(rt), l, v);
			else update(rson(rt), l, v);
			tr[rt].mmax = max(tr[lson(rt)].mmax, tr[rson(rt)].mmax);
		}
	}

	LL query(int rt, int l, int r) {
		if (tr[rt].l > r || tr[rt].r < l) return 0;
		if (tr[rt].l >= l && tr[rt].r <= r) {
			return tr[rt].mmax;
		} else {
			int mid = tr[lson(rt)].r;
			if (r <= mid) return query(lson(rt), l, r);
			if (l >  mid) return query(rson(rt), l, r);
			return max(query(lson(rt), l, r), query(rson(rt), l , r));
		}
	}
};

SegmentTree st;
const int MAX_LOG = 18;
int n, q;
int x, y;
int p[MAX_N], l[MAX_N];
int rgt[MAX_N];
int U[MAX_LOG][MAX_N], S[MAX_LOG][MAX_N];

int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", p + i, l + i);
	}
	st.build(1, 1, n);

	rgt[n] = p[n] + l[n];
	st.update(1, n, rgt[n]);
	for (int i = n - 1; i >= 1; i--) {
		int pos = upper_bound(p + 1, p + n + 1, p[i] + l[i]) - p - 1;
		rgt[i] = st.query(1, i+1, pos);
		rgt[i] = max(rgt[i], p[i] + l[i]);
		st.update(1, i, rgt[i]);
	}
	for (int i = 1; i <= n; i++) {
		int pos = upper_bound(p + 1, p + n + 1, rgt[i]) - p;
		S[0][i] = (pos <= n ? (p[pos] - rgt[i]) : 0);
		if (pos > n) U[0][i] = -1;
		else U[0][i] = pos;
	}
	
	for (int k = 1; k < MAX_LOG; k++) {
		for (int i = 1; i <= n; i++) {
			if (U[k - 1][i] == -1 || U[k - 1][U[k - 1][i]] == -1) {
				U[k][i] = -1;
				S[k][i] = 0;
			}
			else  {
				U[k][i]	= U[k - 1][U[k-1][i]];
				S[k][i] = S[k - 1][i] + S[k - 1][U[k - 1][i]];
			}
		}
	}

	scanf("%d", &q);
	while (q--) {
		scanf("%d %d", &x, &y);
		int res = 0;
		for (int k = MAX_LOG - 1; k >= 0; k--) {
			if (U[k][x] != -1 && U[k][x] <= y) {
				res += S[k][x];
				x = U[k][x];
			}
		}
		printf("%d\n", res);
	}

	return 0;
}
