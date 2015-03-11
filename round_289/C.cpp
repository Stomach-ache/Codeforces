/*************************************************************************
    > File Name: C.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com 
    > Created Time: 2015年01月31日 星期六 20时28分08秒
 ************************************************************************/

#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<cstdio>
#include<vector>
#include<string>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int cmp(char *a, char *b) {
	if (strlen(a) < strlen(b)) return -1;
	if (strlen(a) > strlen(b)) return 1;
	if (strcmp(a, b) == 0) return 0;
	for (int i = 0; i < strlen(a); i++) if (a[i] < b[i]) return -1;
	return 1;
}

char lst[1000], now[1000];

int main(void) {
	int n;
	scanf("%d", &n);
	int pre = 0;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		int cur = 0;
		for (int i = 9; i >= 1; i--) {
			while (x >= i) {
				for (int j = 0; j < x/i; j++) {
					printf("%d", i);
					now[cur++] = i + '0';
				}
				x %= i;
			}
		}
		while (cur < pre || cur==pre&&cmp(lst, now)>=0) {
			putchar('0');
			now[cur++] = '0';
		}
		puts("");

		pre = cur;
		swap(lst, now);
		now[0] = '\0';
	}

	return 0;
}
