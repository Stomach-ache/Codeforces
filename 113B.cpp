/*************************************************************************
    > File Name: 113B.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年07月18日 星期五 22时08分53秒
    > Propose: 
 ************************************************************************/
#include <set>
#include <cmath>
#include <string>
#include <cstdio>
#include <vector>
#include <fstream>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

string t, b, e;
int flag1[2002], flag2[2002];
int len1, len2, len3;
typedef unsigned long long ull;
vector<ull> ans;

void
solve(int x) {
	ull tt = 0;
  	for (int i = x; i < len1; i++) {
	  	tt = tt * 31 + t[i];
		if (flag2[i] == 1 && i-x+1 >= max(len2, len3)) ans.push_back(tt);
	}
}

int
main(void) {
		cin >> t;
	  	cin >> b;
		cin >> e;
		len1 = (int)t.size();
		len2 = (int)b.size();
		len3 = (int)e.size();
		int maxl = max(len2, len3);
		for (int i = 0; i < len1; i++) {
		  	if (t.substr(i, len2) == b) flag1[i] = 1;
			if (t.substr(i, len3) == e) flag2[i+len3-1] = 1; 
		}
		for (int i = 0; i < len1; i++) if (flag1[i]) {
		  	solve(i);
		}
		sort(ans.begin(), ans.end());
		ans.resize(unique(ans.begin(), ans.end())-ans.begin());
		printf("%d\n", ans.size());

	return 0;
}
