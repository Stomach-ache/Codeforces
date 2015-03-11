/*************************************************************************
    > File Name: C.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年11月11日 星期二 23时31分46秒
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
/*Let's fight!!!*/

char s[100050];
int n, p;

int main(void) {
  	scanf("%d %d", &n, &p);
	scanf("%s", s + 1);

	int lft = p, rgt = p;
	int res = 0;
	if (p > n / 2) p = n - p + 1;
	if (p <= n / 2) {
	  	for (int i = p; i <= n/2; i++) if (s[i] != s[n - i + 1]) rgt = i;
		for (int i = p; i >= 1; i--) if (s[i] != s[n - i + 1]) lft = i;
		if (p - lft < rgt - p) {
			if (s[p] != s[n - p + 1]) {
				res += min(abs(s[p] - s[n - p + 1]), 26 - abs(s[p] - s[n - p + 1]));
				s[p] = s[n - p + 1];
			}
		  	for (int i = p - 1; i >= lft; i--) {
			  	res++;
				if (s[i] != s[n - i + 1]) {
					res += min(abs(s[i] - s[n - i + 1]), 26 - abs(s[i] - s[n - i + 1]));
					s[i] = s[n - i + 1];
				}
			}
			res += p - lft;
			if (s[p] != s[n - p + 1]) {
				res += min(abs(s[p] - s[n - p + 1]), 26 - abs(s[p] - s[n - p + 1]));
				s[p] = s[n - p + 1];
			}
			for (int i = p + 1; i <= rgt; i++) {
			  	res++;
				if (s[i] != s[n - i + 1]) {
					res += min(abs(s[i] - s[n - i + 1]), 26 - abs(s[i] - s[n - i + 1]));
					s[i] = s[n - i + 1];
				}
			}
		} else {
			if (s[p] != s[n - p + 1]) {
				res += min(abs(s[p] - s[n - p + 1]), 26 - abs(s[p] - s[n - p + 1]));
				s[p] = s[n - p + 1];
			}
		  	for (int i = p + 1; i <= rgt; i++) {
			  	res++;
				if (s[i] != s[n - i + 1]) {
					res += min(abs(s[i] - s[n - i + 1]), 26 - abs(s[i] - s[n - i + 1]));
					s[i] = s[n - i + 1];
				}
			}
			res += rgt - p;
			if (s[p] != s[n - p + 1]) {
				res += min(abs(s[p] - s[n - p + 1]), 26 - abs(s[p] - s[n - p + 1]));
				s[p] = s[n - p + 1];
			}
			for (int i = p - 1; i >= lft; i--) {
			  	res++;
				if (s[i] != s[n - i + 1]) {
					res += min(abs(s[i] - s[n - i + 1]), 26 - abs(s[i] - s[n - i + 1]));
					s[i] = s[n - i + 1];
				}
			}
		} 
	}
	printf("%d\n", res);

	return 0;
}
