/*************************************************************************
    > File Name: c.c
    > Author: Stomach_ache
    > Mail: 1179998621@qq.com 
    > Created Time: 2013年12月30日 星期一 01时03分02秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char map[505][505];
int n, m, k, vis[505][505];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

//判断是否该联通分量只有一个点, 若是则返回0, 否则返回1
int ok(int x, int y) {
	int i;
	if (map[x][y] != '.')
		return 0;
	int f = 0;
	for (i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx >=n || xx < 0 || yy >= m || yy < 0)
			continue;
		if (map[xx][yy] == '.') {
			f = 1;
			break;
		}
	}

	return f;
}

void dfs(int x, int y) {
	int i;
	for (i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx >= n || xx < 0 || yy >=m || yy < 0)
			continue;
		if (map[xx][yy] == '.' && !vis[xx][yy]) {
			vis[xx][yy] = 1;
			dfs(xx, yy);
			//break;
		}
	}
	if (k <= 0)
		return ;
	map[x][y] = 'X';
	k--;

	return ;
}

int main(void) {
	while (~scanf("%d %d %d", &n, &m, &k)) {
		int i, j;
		for (i = 0; i < n; i++) {
			scanf("%s", map[i]);
			/* puts(map[i]); */
		}
		while (k) {
			memset(vis, 0, sizeof(vis));
			for (i = 0; i < n && k > 0; i++) {
				for (j = 0; j < m && k > 0; j++) {
					if (ok(i, j)) {
						vis[i][j] = 1;
						dfs(i, j);
						/* k--; */
					}
				}
			}
		}
		for (i = 0; i < n; i++)
			puts(map[i]);
	}

	return 0;
}
