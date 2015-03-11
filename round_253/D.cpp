/*************************************************************************
    > File Name: 442B.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年06月23日 星期一 14时19分19秒
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

#define eps 1e-9
int n;
double p[105];

double cal(int x) {
  	double result = 0.0;
	for (int i = x; i < n; i++) {
	  	double tmp = p[i];
		for (int j = x; j < n; j++) {
		  	if (i == j) continue;
		  	tmp *= (1.0 - p[j]);
		}
		result += tmp;
	}
	return result;
}

int
main(void) {
  	while (~scanf("%d", &n) && n) {
	  	for (int i = 0; i < n; i++) scanf("%lf", p+i);
		sort(p, p + n);
		double ans = p[n-1];
		for (int i = n-2; i >= 0; i--) {
		  	double tmp = cal(i);
			if (tmp - ans < eps) break;
			ans = tmp;
		}
		printf("%.17f\n", ans);
	}

	return 0;
}
