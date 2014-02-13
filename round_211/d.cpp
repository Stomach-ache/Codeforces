#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, a, p[100005], b[100005];

int cmp(int x, int y) {
	return x < y;
}

int main(void) {
	while (~scanf("%d %d %d", &n, &m, &a)) {
		int i;
		for (i=0; i<n; i++) 
			scanf("%d", &b[i]);

		for (i=0; i<m; i++)
			scanf("%d", &p[i]);

		int r, s, lft = a;
		r = s = 0;
		sort(b, b+n, cmp);
		sort(p, p+m, cmp);

		for (i=0; i<m; i++) {
			it = lower_bound(b, b+n, p[i])-b;
			if (it2>=0 && b[it2]+lft >= p[i]) {
				r++;
				s += p[i];
				lft -= p[i]-b[it2];
				b.erase(it2);
			}
			else if (it != b.size()){
				int tmp = b.size()-1;
				if (b[tmp]+lft >= p[i]) {
					r++;
					s += p[i];
					lft -= p[i]-b[tmp];
					b.pop_back();
				}
				else 
					break;
			}
		}
		s -= a;
		printf("%d %d\n", r, s);
	}

	return 0;
}
