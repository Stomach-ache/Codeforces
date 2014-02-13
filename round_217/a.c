/*************************************************************************
    > File Name: a.c
    > Author: Stomach_ache
    > Mail: 1179998621@qq.com 
    > Created Time: 2013年12月07日 星期六 14时54分30秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int r1, c1, r2, c2;


int main(void) {
	while (~scanf("%d %d %d %d", &r1, &c1, &r2, &c2)) {
		int rook = 2;
		if (r1 == r2 || c1 == c2)
			rook = 1;

		int bishop;
		if ((abs(r2 - r1) + abs(c2 - c1)) % 2 == 1)
			bishop = 0;
		else {
			if (r2 == r1 || c2 == c1)
				bishop = 2;
			else {
				int k = (r2 - r1) / (c2 - c1);
				if (k == 1 || k == -1)
					bishop = 1;
				else
					bishop = 2;
			}
		}
		
		int king;
		if (r2 == r1)
			king = abs(c2 - c1);
		else if (c2 == c1)
			king = abs(r2 - r1);
		else {
			int a = abs(r2 - r1);
			int b = abs(c2 - c1);
			if (a < b)
				king = b;
			else
				king = a;
		}
		printf("%d %d %d\n", rook, bishop, king);
	}

	return 0;
}
