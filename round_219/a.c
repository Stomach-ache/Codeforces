/*************************************************************************
    > File Name: a.c
    > Author: Stomach_ache
    > Mail: 1179998621@qq.com 
    > Created Time: 2013年12月13日 星期五 22时29分33秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int k, time[20];

int main(void) {
	while (~scanf("%d", &k)) {
		int i, j;
		memset(time, 0, sizeof(time));
		for (i = 0 ; i < 4; i++) {
			char str[10];
			scanf("%s", str);
			for (j = 0; j < 4; j++) {
				if (str[j] != '.') 
					time[str[j]-'0']++;
			}
		}
		int flag = 1;
		for (i = 1; i <= 9; i++) {
			if (time[i] > 2 * k) {
				flag = 0;
				break;
			}
		}

		if (flag)
			puts("YES");
		else
			puts("NO");
	}

	return 0;
}
