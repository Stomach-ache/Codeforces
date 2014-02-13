#include <stdio.h>
#include <string.h>

int cnt[5];

int main(void){
	int n;
	while (~scanf("%d", &n)) {
		memset(cnt, 0, sizeof(cnt));
		int i;
		for (i=0; i<n; i++) {
			int a;
			scanf("%d", &a);
			cnt[a]++;
		}
		int ans = 0;
		if (cnt[1] >= cnt[2]) {
			ans += cnt[2];
			cnt[3] += cnt[2];
			cnt[1] -= cnt[2];
			cnt[2] = 0;
		}
		else if (cnt[1]+cnt[4] >= cnt[2]) {
			ans += cnt[2];
			cnt[3] += cnt[2];
			cnt[4] -= cnt[2]-cnt[1];
			cnt[1] = cnt[2] = 0;
		}
		else {
			ans += cnt[1]+cnt[4];
			cnt[3] += cnt[1]+cnt[4];
			cnt[2] -= cnt[1]+cnt[4];
			cnt[1] = cnt[4] = 0;
		}
		if (cnt[1] > 0) {
			ans += cnt[1]/3*2;
			cnt[3] += cnt[1]/3;
			cnt[1] %= 3;
			if (cnt[1] <= cnt[3]) {
				ans += cnt[1];
				cnt[3] -= cnt[1];
				cnt[4] += cnt[1];
				cnt[1] = 0;
			}
			if (3-cnt[1]<=cnt[4] && cnt[1]!=0) {
				ans += cnt[1]-1;
				ans += 3-cnt[1];
				cnt[4] -= 3-cnt[1];
				cnt[3]++;
				cnt[1] = 0;
			}
			if (cnt[1] > 0) {
				if (cnt[1] <= cnt[3]) {
					ans += cnt[1];
					cnt[3] -= cnt[1];
					cnt[4] += cnt[1];
					cnt[1] = 0;
				}
			}
		}
		if (cnt[2] > 0) {				
			int tmp = cnt[2]*2;
			ans += tmp/3;
			cnt[3] += tmp/3;
			cnt[2] = 0;
			if (tmp%3 == 1) {
				cnt[1] = 1;
				if (cnt[3] >= 1) {
					ans++;
					cnt[4] += 1;
					cnt[3] -= 1;
					cnt[1] = 0;
				}
			}
			else if (tmp%3 == 2) {
				cnt[2] = 1;
				if (cnt[3] >= 2) {
					ans += 2;
					cnt[3] -= 2;
					cnt[4] += 2;
					cnt[2] = 0;
				}
			}
		}
		if (cnt[1]==0 && cnt[2]==0)
			printf("%d\n", ans);
		else
			puts("-1");
	}

	return 0;
}
