/*************************************************************************
    > File Name: 425B.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年04月30日 星期三 21时44分14秒
    > Propose: 
 ************************************************************************/

#include <cmath>
#include <string>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N (100 + 5)
#define min(x, y) ((x) < (y) ? (x) : (y))

int n, m, k;
int a[MAX_N][MAX_N];

int
main(void) {
		scanf("%d %d %d", &n, &m, &k);
		for (int i = 0; i < n; i++) 
				for (int j = 0; j < m; j++) 
						scanf("%d", &a[i][j]);
		int ans = 10005;
		if (k < n) {
				for (int i = 0; i < n; i++) {
						int tmp = 0;
						for (int j = 0; j < n; j++) if (i != j) {
								int cnt1 = 0, cnt2 = 0;
								for (int t = 0; t < m; t++) {
										if (a[j][t] == a[i][t]) {
												cnt1++;
										} else {
												cnt2++;
										}
								}
								tmp += min(cnt1, cnt2);
						}
						if (tmp < ans) {
								ans = tmp;
						}
				}
		} else {
				for (int i = 0; i < (1<<n); i++) {
						int tmp = 0, b[MAX_N];
						for (int j = 0; j < n; j++) {
								if (i & (1<<j)) {
										if (a[j][0] == 0) {
												b[j] = 1;
												tmp++;
										} else {
												b[j] = 1;
										}
								} else {
										if (a[j][0] == 1) {
												b[j] = 0;
												tmp++;
										} else {
												b[j] = 0;
										}
								}
						}
						for (int j = 1; j < m; j++) {
								int cnt1 = 0, cnt2 = 0;
								for (int t = 0; t < n; t++) {
										if (a[t][j] == b[t]) {
												cnt1++;
										} else {
												cnt2++;
										}
								}
								tmp += min(cnt1, cnt2);
						}
						if (tmp < ans) {
								ans = tmp;
						}
				}
		}
		if (ans > k) {
				puts("-1");
		} else {
				printf("%d\n", ans);
		}
		
		return 0;
}
