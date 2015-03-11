/*************************************************************************
    > File Name: C.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年09月12日 星期五 23时42分44秒
    > Propose: 
 ************************************************************************/

#include <cmath>
#include <string>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/*Let's fight!!!*/

typedef long long LL;
const int MAX_N = 500050;
LL n;
LL a[MAX_N], sum[MAX_N];
#define rep(i, n) for (LL i = (1); i <= (n); i++)

int main(void) {
  	ios::sync_with_stdio(false);
	cin >> n;
	for (LL i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i-1] + a[i]; 
	}
	if (sum[n] % 3) {
	  	cout << "0" << endl;
		return 0;
	}
	LL tmp = sum[n] / 3;
	vector<LL> id1, id2;
	for (LL i = 1; i <= n; i++) if (sum[i] == tmp) id1.push_back(i);
	for (LL i = 1; i <= n; i++) if (sum[i] == sum[n]-tmp) id2.push_back(i);
	int sz1 = id1.size(), sz2 = id2.size();
	LL res = 0;
	for (int i = 0; i < sz1; i++) {
	  	if (id1[i] == n) continue;
	  	LL tmp = upper_bound(id2.begin(), id2.end(), id1[i]) - id2.begin();
		res += sz2 - tmp;
		if (id2[sz2-1] == n) res--;
	}
	cout << res << endl;

	return 0;
}
