/*************************************************************************
    > File Name: 372A.c
    > Author: Stomach_ache
    > Mail: 1179998621@qq.com 
    > Created Time: 2013年12月14日 星期六 15时00分11秒
 ************************************************************************/

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<int> s;

int solve() {
	int tmp = upper_bound(s.begin(), s.end(), s[n-1]/2) - s.begin(), 
	    j = tmp, cnt = 0, i = 0;

	while (j < n && i < tmp) {
		if (s[j] >= s[i] + s[i]) {
			cnt++;
			i++, j++;
		}
		else
			j++;
	}

	return cnt;
}

int check(int limit) {
	int i, j = limit;

	for (i = 0; i < limit && j < n;) {
		if (s[j] >= s[i] + s[i]) {
			j++;
			i++;
		}
		else 
			j++;
	}

	return i == limit;
}

int main(void) {
	while (~scanf("%d", &n)) {
		s.clear();
		int i;
		for (i = 0; i < n; i++) {
			int a;
			scanf("%d", &a);
			s.push_back(a);
		}

		sort(s.begin(), s.end());

		int lf = 0, rgt = n / 2, ans = 0;

		while (lf <= rgt) {
			int mid = (lf + rgt) >> 1;

			if (check(mid)) {
				ans = mid;
				lf = mid + 1;
			}
			else
				rgt = mid - 1;
		}

		printf("%d\n", n - ans);
		//printf("%d\n", n - solve());
	}

	return 0;
}
