/*************************************************************************
    > File Name: F.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年10月08日 星期三 14时11分07秒
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

const int MAX_N = 100050;
typedef pair<int, int> pii;
#define lson(x) (x<<1)
#define rson(x) ((x<<1) | 1)
struct node {
  	int l, r, min_val, min_cnt, gg;	
}tr[MAX_N*3];
int s[MAX_N];

int gcd(int a, int b) {
  	if (!b) return a;
	return gcd(b, a % b);
}

void pushup(int rt) {
  	if (tr[lson(rt)].min_val < tr[rson(rt)].min_val) {
	  	tr[rt].min_val = tr[lson(rt)].min_val;
	  	tr[rt].min_cnt = tr[lson(rt)].min_cnt;
	} else if (tr[lson(rt)].min_val > tr[rson(rt)].min_val) {
	  	tr[rt].min_val = tr[rson(rt)].min_val;
	  	tr[rt].min_cnt = tr[rson(rt)].min_cnt;
	} else {
	  	tr[rt].min_val = tr[rson(rt)].min_val;
	  	tr[rt].min_cnt = tr[lson(rt)].min_cnt + tr[rson(rt)].min_cnt;
	}
	tr[rt].gg = gcd(tr[lson(rt)].gg, tr[rson(rt)].gg);
}

void build(int rt, int l, int r) {
  	tr[rt].l = l, tr[rt].r = r;
	if (l == r) {
	  	tr[rt].min_val = s[l];
		tr[rt].min_cnt = 1;
		tr[rt].gg = s[l];
		return ;
	}
	int mid = (l + r) >> 1;
	build(lson(rt), l, mid);
	build(rson(rt), mid + 1, r);
	pushup(rt);
}

pii query_min(int rt, int l, int r) {
  	if (tr[rt].l >= l && tr[rt].r <= r) {
	  	return pii(tr[rt].min_val, tr[rt].min_cnt);
	}
	int mid = tr[lson(rt)].r;
	pii lans = make_pair(0x3f3f3f3f, 0), rans = make_pair(0x3f3f3f3f, 0);
	if (l <= mid) lans = query_min(lson(rt), l, r);
	if (r > mid)  rans = query_min(rson(rt), l, r);
	if (lans.first == rans.first) return pii(lans.first, lans.second + rans.second);
	else return min(lans, rans);
}

int query_gcd(int rt, int l, int r) {
  	if (tr[rt].l >= l && tr[rt].r <= r) {
	  	return tr[rt].gg;
	}
	int mid = tr[lson(rt)].r;
	if (r <= mid) return query_gcd(lson(rt), l, r);
	if (l > mid)  return query_gcd(rson(rt), l, r);
	else return gcd(query_gcd(lson(rt), l, r), query_gcd(rson(rt), l, r)); 
}

int main(void) {
  	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> s[i];
	build(1, 1, n);

	int m;
	cin >> m;
	while (m--) {
	  	int l, r;
		cin >> l >> r;
		pii ans = query_min(1, l, r);
		int g = query_gcd(1, l, r);
		if (g != ans.first) cout << r - l + 1 << endl;
		else cout << r - l + 1 - ans.second << endl;
	}

	return 0;
}
