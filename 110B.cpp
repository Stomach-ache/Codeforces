/*************************************************************************
    > File Name: 110B.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年07月18日 星期五 21时26分00秒
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

int n;

char a[] = {'a', 'b', 'c', 'd'};

int
main(void) {
  	while (~scanf("%d", &n)) {
	  	for (int i = 0; i < n; i++) {
		 // 	if (i % 5 == 0) putchar('a');
			putchar(a[i%4]);
		}
		puts("");
	}

	return 0;
}
