#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

struct node {
	int c, p, id, table_id;
};
typedef pair<int, int> pii;

int n, k, vis[1005];
node group[1005];
pair<int, int> table[1005];

int cmp(const node& x, const node& y) {
	return x.p > y.p || (x.p == y.p && x.c > y.c);
}

int main(void) {
	while (~scanf("%d", &n) && n) {
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &group[i].c, &group[i].p);
			group[i].id = i + 1;
			group[i].table_id = -1;
		}
		scanf("%d", &k);
		for (int i = 0; i < k; i++) {
			int r;
			scanf("%d", &r);
			table[i] = pii(r, i+1);
		}
		sort(group, group+n, cmp);
		sort(table, table+k);

		//printf("%d %d\n", group[0].p, group[0].c);
		//printf("%d %d\n", group[1].p, group[1].c);

		int cnt = 0, money = 0;
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; i++) {
			//printf("%d %d\n", group[i].p, group[i].c);
			for (int j = 0; j < k; j++) {
				if (!vis[j] && group[i].c <= table[j].first) {
					cnt++;
					money += group[i].p;
					group[i].table_id = table[j].second;
					vis[j] = 1;
					break;
				}
			}
		}

		printf("%d %d\n", cnt, money);
		for (int i = 0; i < n; i++) {
			if (group[i].table_id != -1) {
				printf("%d %d\n", group[i].id, group[i].table_id);
			}
		}
	}

	return 0;
}