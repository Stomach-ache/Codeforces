#include <cstdio>
#include <cstring>

int b[100005];
bool a[100005][32], able[100005];
int n;

int main(void) {
	while (~scanf("%d", &n) && n) {
		memset(a, false, sizeof(a));
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			b[i] = x;
			for (int j = 30; j >= 0; j--) {
				if ((1 << j) & x)
					a[i][30-j] = true;
			}
		}

		int cnt;
		for (int i = 0; i <= 30; i++) {
			cnt = 0;
			memset(able, false, sizeof(able));
			for (int j = 0; j < n; j++) {
				if ( a[j][i] ) {
					able[j] = true;
					cnt++;
				}
			}
			if (cnt == 0) continue;

			int j;
			for (j = i + 1; j <= 30; j++) {
				int f = 0;
				for (int k = 0; k < n; k++) {
					if ( able[k] ) {
						if ( !a[k][j] ) {
							f = 1;
							break;
						}
					}
				}
				if (f == 0)
					break;
			}
			if (j > 30)
				break;
		}
		printf("%d\n", cnt);
		int flag = 0;
		for (int i = 0; i < n; i++) {
			if ( able[i] ) {
				if (flag) 
					printf(" ");
				flag = 1;
				printf("%d", b[i]);
			}
		}
		puts("");
	}

	return 0;
}
