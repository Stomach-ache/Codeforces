#include <iostream>
#include <cstring>
#include <set>

using namespace std;

int color[300005];

int main(){
	int n, m;
	while (cin >> n >> m) {
		set<int> my_set;
		for (int i = 1; i <= n; i++) {
			my_set.insert(i);
		}
		memset(color, 0, sizeof(color));

		for (int i = 0; i < m; i++) {
			int l, r, x;
			cin >> l >> r >> x;
			set<int>::iterator it;
			it = my_set.lower_bound(l);
			while (it != my_set.end()) {
				if ((*it) > r) {
					break;
				}
				if ((*it) == x) {
					it++;
					continue;
				}
				color[(*it)] = x;
				my_set.erase(it++);
				/* it++; */
			}
		}
		for (int i = 1; i <= n; i++) {
			cout << color[i] << (i==n ? '\n' : ' ');
		}
	}

	return 0;
}
