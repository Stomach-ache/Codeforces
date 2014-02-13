#include <stdio.h>
#include <string.h>

char a[200005];

int main(void)
{
	while (~scanf("%s", a)) {
		int len = strlen(a), i, pre = 0;
		putchar(a[0]);
		for (i=1; i<len; i++) {
			if (a[i] != a[i-1]) {
				putchar(a[i]);
				if (pre < 2) {
					pre = 1;
				}
				else {
					int j = i;
					while (a[j] == a[i])
						j++;
					i = j-1;
					pre = 1;
				}
			}
			else {
				if (pre < 2) {
					putchar(a[i]);
					pre = 2;
				}
			}
		}
		puts("");
	}

	return 0;
}
