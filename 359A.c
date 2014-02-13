#include <stdio.h>

#define min(x, y) ((x)<(y)?(x):(y))
#define max(x, y) ((x)>(y)?(x):(y))

int main(void){
	int n, m;
	while (~scanf("%d %d", &n, &m)) {
		int i, j, flag = 0;
		for (i=0; i<n; i++) {
			for (j=0; j<m; j++) {
				int a;
				scanf("%d", &a);
				if (a) {
				     if (i==0 || i==n-1 || j==0 || j==m-1)
					     flag = 1;
				}
			}
		}
		if (flag)
			puts("2");
		else
			puts("4");
	}

	return 0;
}
