/*************************************************************************
    > File Name: B.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年08月08日 星期五 23时39分10秒
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

char s[100005];

int main(void) {
  	while (~scanf("%s", s)) {
	  	int len = (int)strlen(s);
		int ans = 1;
		if ((s[len-1] - '0') % 2) ans += 4;
		else ans += 1;
		int tmp = 0;
		for (int i = 0; i < len; i++) {
		  	tmp = tmp * 10 + s[i] - '0';
			tmp %= 4;
		}
		if (tmp == 0) ans += 2;
		else if (tmp == 1) ans += 5;
		else if (tmp == 2) ans += 8;
		else ans += 5;
		printf("%d\n", ans % 5);
	}
	return 0;
}
