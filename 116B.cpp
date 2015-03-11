/*************************************************************************
    > File Name: 116B.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年07月18日 星期五 21时16分26秒
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

int n, m;
char a[12][12];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int 
main(void) {
  	while (~scanf("%d %d", &n, &m)) {
	  	for (int i = 0; i < n; i++) scanf("%s", a[i]);
		int ans = 0;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) 
		  	if (a[i][j] == 'P') {
			  	for (int k = 0; k < 4; k++) {
				  	int x = dx[k] + i;
					int y = dy[k] + j;
					if (x >= 0 && x < n && y >= 0 && y < m) {
					  	if (a[x][y] == 'W') {
							ans++;
							a[x][y] = '.';
						}
					}
				}
			}
		printf("%d\n", ans);
	}

	return 0;
}
