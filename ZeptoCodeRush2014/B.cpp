/*************************************************************************
    > File Name: B.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年06月14日 星期六 00时16分54秒
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

int n, m, k;
char map[2005][2005];

int
main(void) {
  	while (~scanf("%d %d %d", &n, &m, &k)) {
	  	for (int i = 0; i < n; i++) scanf("%s", map[i]);
		for (int i = 0; i < m; i++) {
		  	int ans = 0;
		  	for (int j = 1; j < n; j++) {
			  	if (i-j >= 0 && map[j][i-j]=='R') ans++;
				if (i+j < m && map[j][i+j] == 'L') ans++;
				if (j+j < n && map[j+j][i] == 'U') ans++;
			}
			printf("%d%c", ans, i == m-1 ? '\n' : ' ');
		}
	}
	return 0;
}
