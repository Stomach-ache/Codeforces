#include <stdio.h>

int main(void){
	int n;
	while (~scanf("%d", &n)) {
		int i, j, beg, end;
		beg = 1;
		end = n*n;
		for (i=1; i<=n; i++) {
			printf("%d %d", beg++, end--);
			for (j=2; j<=n/2; j++,beg++,end--) {
				printf(" %d %d", beg, end);
			}
			puts("");
		}
	}

	return 0;
}
