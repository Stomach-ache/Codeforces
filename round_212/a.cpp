/*
   时间：2013-11-15-22时28分42秒
   悲剧的写了个双广，最后却是个规律题。。。
   规律：如果第一次不能相遇（在#上相遇也算）那么就不会相遇
 */
#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;

int vis[9][9], vis2[9][9], t, dx[]={2, 2, -2, -2}, dy[]={2, -2, 2, -2};
char map[9][9];
int sx, sy, ex, ey;

int ok(int xx, int yy) {
	if (xx>=0 && xx<8 && yy>=0 && yy<8) {
		return 1;
	}

	return 0;
}

typedef pair<int, int> pii;
int bfs() {
	vis[sx][sy] = vis2[ex][ey] = 0;
	queue<pii> q, q2;
	q.push(pii(sx,sy));
	q2.push(pii(ex,ey));

	int s = 0;
	while (1) {
		if (q.empty() && q2.empty())
			break;
		while (!q.empty()) {
			pii cur = q.front();
			int i, x = cur.first, y = cur.second;
			if (vis[x][y] != s)
				break;
			q.pop();
			if (vis2[x][y]!=-1 && vis[x][y]==vis2[x][y]) {
				return 1;
			}
			for (i=0; i<4; i++) {
				int xx = x+dx[i];
				int yy = y+dy[i];
				if (ok(xx, yy)) {
					q.push(pii(xx, yy));
					vis[xx][yy] = vis[x][y]+1;
				}
			}
		}
		while (!q2.empty()) {
			pii cur = q2.front();
			int i, x = cur.first, y = cur.second;
			if (vis2[x][y] != s)
				break;
			q2.pop();
			if (vis[x][y]!=-1 && vis[x][y]==vis2[x][y])
				return 1;
			for (i=0; i<4; i++) {
				int xx = x+dx[i];
				int yy = y+dy[i];
				if (ok(xx, yy)) {
					q2.push(pii(xx, yy));
					vis2[xx][yy] = vis2[x][y]+1;
				}
			}
		}
		s++;
		if (s >= 2)
			return 0;
	}

	return 0;
}

int main(void) {
	scanf("%d", &t);
	while (t--) {
		int i, flag = 0;
		for (i=0; i<8; i++) {
			scanf("%s", map[i]);
			int j;
			for (j=0; j<8; j++) {
				if (map[i][j]=='K') {
					if (flag == 0) {
						sx = i;
						sy = j;
					}
					else {
						ex = i;
						ey = j;
					}
					flag = 1;
				}
			}
		}
		memset(vis, -1, sizeof(vis));
		memset(vis2, -1, sizeof(vis2));
		if (bfs()) 
			puts("YES");
		else
			puts("NO");
	}

	return 0;
}
