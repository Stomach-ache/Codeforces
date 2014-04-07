#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, k, d[100005], vis[100005];
typedef pair<int, int> pii;
#define max(x, y) ((x) > (y) ? (x) : (y))

int main() {
	while (~scanf("%d %d", &n, &k)) {
		vector<pii> my_pair, ans;
		int max_dist = -1, s;
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= n; i++) {
			scanf("%d", d + i);
			my_pair.push_back(d[i], i);
			vis[d[i]]++;
			if (d[i] == 0)
				s = i;
			max_dist = max(max_dist, d[i]);
		}
		sort(my_pair.begin(), my_pair.end());
		int cur_dist = 1, cnt = 0, pre_dist_num = 1, iter = 0;
		if (vis[0] > 1) {
			puts("-1");
			continue;
		}
		queue<int> q, tmp;
		q.push(i);
		while (cur_dist <= max_dist) {
			int x = q.front(); q.pop();
			if (vis[cur_dist] > pre_dist_num * k) {
				puts("-1");
				break;
			}
			pre_dist_num = vis[cur_dist];
			while (my_pair[iter].first == cur_dist) {
				tmp.push(my_pair[iter].second);
				ans.push_back(pii(x, my_pair[iter++].second));
			}
		}
		int m = ans.size();
		printf("%d\n", m);
		for (size_t i = 0; i < m; i++)
			printf("%d %d\n", ans[i].first, ans[i].second);
	}

	return 0;
}