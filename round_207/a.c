#include <stdio.h>

int c[105];

int main(){
	int m;
	while (~scanf("%d", &m)){
		int x, y, i, ans, cnt, sum = 0;
		for (i = 1; i <= m; i++){
			scanf("%d", &c[i]);
			sum += c[i];
		}
		scanf("%d %d", &x, &y);
		ans = cnt = 0;
		for (i = 1; i <= m; i++){
			cnt += c[i];
			if ((cnt>=x && cnt<=y) && (sum-cnt>=x && sum-cnt<=y)){
				ans = i + 1;
				break;
			}
		}
		printf("%d\n", ans);
	}
}
