/*************************************************************************
    > File Name: A.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年07月24日 星期四 23时32分57秒
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

int n, m;
bool vis1[102], vis2[102];

int main(void) {
  	scanf("%d %d", &n, &m);
	memset(vis1, false, sizeof(vis1));
	memset(vis2, false, sizeof(vis2));
	int ans = 0;
	for (int k = 0; k < 100; k++) {
	  	int f = 0;
	  	for (int i = 1; i <= n; i++) {
		  	 for (int j = 1; j <= m; j++) {
			   	if (!vis1[i] && !vis2[j]) {
				  	vis1[i] = vis2[j] = true;
					f = 1;
					break;
				}
			 }
			 if (f) break;
		}
		if (!f) {
		  	break;
		}
		ans = ans ^ 1;
	}
	if (!ans) puts("Malvika");
	else puts("Akshat");
	
	return 0;
}
