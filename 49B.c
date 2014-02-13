/*************************************************************************
    > File Name: 49B.c
    > Author: Stomach_ache
    > Mail: 1179998621@qq.com 
    > Created Time: 2013年12月02日 星期一 22时50分01秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define max(x,y) ((x)>(y)?(x):(y))

int a, b;

int cal(int n) {
	int res = 0;
	while (n) {
		res = max(res, n%10);
		n /= 10;
	}

	return res;
}

int main(void) {
	while (~scanf("%d %d", &a, &b)) {
		int base = 0;
		base = max(base, cal(a)+1);
		base = max(base, cal(b)+1);

		int len = 0, car = 0;
		while (a || b) {
			int tmp = a%10 + b%10 + car;
			car = tmp / base;
			a /= 10;
			b /= 10;
			len++;
		}
		if (car) 
			len++;

		printf("%d\n", len);
	}

	return 0;
}
