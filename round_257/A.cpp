/*************************************************************************
    > File Name: A.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年07月19日 星期六 21时06分21秒
    > Propose: 
 ************************************************************************/

#include <queue>
#include <cmath>
#include <string>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int a[105];

int
main(void) {
  	int n, m;
	typedef pair<int, int> pii;
	queue<pii> q;
	scanf("%d %d", &n, &m);
	for (int i = 1;i <= n; i++) {
	  	int a;
		scanf("%d", &a);
		q.push(pii(a, i));
	}
	int c = 0, ans;
	while (c < n) {
	  	pii a = q.front();
		q.pop();
	  	if (a.first > m) {
		  q.push(pii(a.first-m, a.second));
		} else {
		  	c++;
			ans = a.second;
		}
	}
	printf("%d\n", ans);
	return 0;
}	
