/*************************************************************************
    > File Name: 110C.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年07月20日 星期日 11时52分09秒
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

int
main(void) {
  	int n;
	scanf("%d", &n);
	int cnt4 = -1, cnt7;
	for (int i = 0; i*4 <= n; i++) {
	  	if ((n - 4*i) % 7 == 0) {
		  	cnt4 = i;
			cnt7 = (n - 4*i) / 7;
			break;
		}
	}
	if (cnt4 == -1) {
		puts("-1");
		return 0;
	}
	for (int i = 0; i < cnt4; i++) putchar('4');
	for (int i = 0; i < cnt7; i++) putchar('7');
	puts("");

	return 0;
}
