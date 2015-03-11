/*************************************************************************
    > File Name: F.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年09月11日 星期四 21时49分50秒
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

const int MAX_N = 100005;
string s[MAX_N], res[MAX_N];
#define rep(i, n) for (int i = (0); i < (n); i++)

int main(void) {
  	ios::sync_with_stdio(false);
	int n = 0;
  	while (cin >> s[n]) n++;
	int cnt, pre;
	for (int i = 0; i < n; i++) {
	  	if (!i || s[i][0] != s[pre][0]) cnt = 0, pre = i;
	  	string tmp = "";
		int j = 0, len = s[i].length();
		while (j < len && j < cnt && s[i][j] == s[i-1][j]) tmp += ' ', j++;
		res[i] = tmp + s[i];
		cnt = (int)tmp.length() + 1;
	}
	rep (i, n) cout << res[i] << endl;

	return 0;
}
