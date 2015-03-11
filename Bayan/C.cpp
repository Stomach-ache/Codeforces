/*************************************************************************
    > File Name: C.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年10月05日 星期日 22时48分54秒
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

int n, m, lstRow[1005], lstCol[1005];
char a[1005][1005];
bool vis[1005][1005];

int main(void) {
  	scanf("%d %d", &n, &m);
	int sx = -1, sy = -1;
	for (int i = 0; i < n; i++) {
	  	scanf("%s", a[i]);
		memset(lstRow, -1, sizeof(lstRow));
		memset(lstCol, -1, sizeof(lstCol));
		memset(vis, false, sizeof(vis));
		for (int j = 0; j < m; j++) {
		  	if (a[i][j] == 'X') {
			  	lstRow[i] = j, lstCol[j] = i;
				if (sx == -1 && sy == -1) {
				  	sx = i; sy = j;
				}
			}
		}
	}
	int h = 1, w = 1;
	bool flag = true;

	int i = sx, j = sy;
	while (i < n && j < m) {
	  	if (a[i][j] != 'X') {
		  	j++;
			if (j == m) {
			  	i++;
				j = 0;
			}
			continue;
		}
	  	vis[i][j] = true;
	  	int rgt = lstRow[i], dwn = lstCol[j];
		for (int k = j; k <= lstRow[i]; k++) if (a[i][k] != 'X') {
		  	flag = false;
			break;
		}
		for (int k = i; k <= lstCol[j]; k++) if (a[k][j] != 'X') {
		  	flag = false;
			break;
		}
		if (!flag) break;
		int ww = lstRow[i] - j + 1;
		int hh = lstCol[j] - i + 1;
		if (ww == hh) {
			for (int k = j+1; k <= j+ww; k++) vis[i][k] = true;
			for (int k = i+1; k <= i+hh; k++) vis[k][j] = true;
		  	i = (i + 1) % n;
			j = (j + 1) % m;
		}
		if (!flag) break;
		if (ww > hh) {
		  	h = max(h, hh);
			for (int k = j+1; k <= j+ww; k++) vis[i][k] = true;
			i++;
		} else {
		  	w = max(w, ww);
			for (int k = i+1; k <= i+hh; k++) vis[k][j] = true;
			j++;
			if (j == m) {
			  	i++;
				j = 0;
			}
		}
	}
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
	  	if (!vis[i][j] && a[i][j] == 'X') flag = false;

	if (!flag) puts("-1");
	else printf("%d\n", w * h);

	return 0;
}
