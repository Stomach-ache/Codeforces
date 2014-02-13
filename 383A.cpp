/*************************************************************************
    > File Name: 383A.c
    > Author: Stomach_ache
    > Mail: 1179998621@qq.com 
    > Created Time: 2014年02月07日 星期五 12时19分24秒
    > Propose: 
 ************************************************************************/
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_N (100000+5)

int n, a[MAX_N], cnt[MAX_N];

int main(void) {
		while (~scanf("%d", &n) && n) {
				int i, num_of_0 = 0, num_of_1;
				for (i = 0; i < n; i++) {
					scanf("%d", a+i);
					if ( !a[i] ) num_of_0++;
				}	
				num_of_1 = n - num_of_0;
				int left_1 = 0, right_0 = num_of_0;
				for (i = 0; i < n; i++) {
						if ( a[i] ) {
								cnt[i] = left_1 + right_0;
								left_1++;
						}
						else {
								cnt[i] = left_1 + right_0 - 1;
								right_0--;
						}
				}
				sort(cnt, cnt+n);
				printf("%d\n", cnt[n-2]);
		}

		return 0;
}
