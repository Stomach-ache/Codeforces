/*************************************************************************
    > File Name: B.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年07月25日 星期五 17时19分46秒
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
const int maxn = 100002;
#define X first
#define Y second
typedef pair<int, int> pii;
int n;
pii a[maxn];

int main(void) {
  	scanf("%d", &n);
	for (int i = 1;i <= n; i++) {
	  	scanf("%d", &a[i].X);
		a[i].Y = i;
	}
	sort(a+1, a+n+1);
	int cnt = 0, flag = 1, beg = 1, end = 1;
	for (int i = 1; i <= n; i++) {
	  	if (a[i].Y == i) continue;
		cnt++;
		if (cnt > 1) {
		  	flag = 0; 
			break;
		}
		beg = i;
		end = a[i].Y;
		i++;
		while (i <= n && a[i].Y == a[i-1].Y - 1) i++;
		if (i <= n) i--;
	}
	if (flag) printf("yes\n%d %d\n", beg, end);
	else puts("no");

	return 0;
}
