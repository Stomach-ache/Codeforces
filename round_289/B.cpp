/*************************************************************************
    > File Name: B.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com 
    > Created Time: 2015年01月31日 星期六 20时18分04秒
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

int color[105][105];
int cnt[105][105];
int a[105];

int main(void) {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", a+i);

	for (int i = 1; i <= n; i++) {
		int c = 1;
		for (int j = 1; j <= a[i]; j++) {
			color[i][j] = c;	
			cnt[i][c]++;
			c++;
			if (c == k+1) c = 1;
		}
	}

	bool flag = true;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) 
		for (int k = 1; k <= 100; k++) if (abs(cnt[i][k] - cnt[j][k]) > 1) {
			flag = false;
			break;
		}

	if (!flag) puts("NO");
	else {
		puts("YES");
		for (int i = 1; i <= n; i++) for (int j = 1; j <= a[i]; j++) 
			printf("%d%c", color[i][j], j == a[i] ? '\n' : ' ');
	}

	return 0;
}
