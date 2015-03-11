/*************************************************************************
    > File Name: B.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年09月26日 星期五 23时45分55秒
    > Propose: 
 ************************************************************************/

#include <cmath>
#include <string>
#include <cstdio>
#include <vector>
#include <fstream>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
/*Let's fight!!!*/

typedef pair<int, int> pii;
int n;
pii a[2005];
#define X first
#define Y second
typedef long long LL;

vector<int> ans[3];
int main(void) {
  	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
	  	scanf("%d", &a[i].X);
		a[i].Y = i;
	}
	sort(a + 1, a + n + 1);

	LL res = 0;
	bool flag = false;
	for (int i = 1; i <= n; i++) {
	  	int cnt = 1, j = i + 1;
		while (j <= n && a[j].X == a[i].X) cnt++, j++;
		if (cnt == 2) res++;
		if (cnt >= 3 || res >= 2) {
		  	flag = true;
			break;
		}
		i = j - 1;
	}
	if (!flag) {
	  	puts("NO");
		return 0;
	}
	puts("YES");
	res = 0;
	int i, j, fir = 0;
	for (i = 1; i <= n; i++) {
	  	int cnt = 1;
		j = i + 1;	
		while (j <= n && a[j].X == a[i].X) cnt++, j++;
		if (cnt == 1) {
		  	ans[0].push_back(a[i].Y);
		  	ans[1].push_back(a[i].Y);
		  	ans[2].push_back(a[i].Y);
		} else if (cnt == 2) {
		  	if (!fir) {
		  		ans[0].push_back(a[i].Y);
			  	ans[1].push_back(a[i+1].Y);
		  		ans[2].push_back(a[i].Y);
		  		ans[0].push_back(a[i+1].Y);
			  	ans[1].push_back(a[i].Y);
		  		ans[2].push_back(a[i+1].Y);
			} else {
		  		ans[0].push_back(a[i+1].Y);
			  	ans[1].push_back(a[i+1].Y);
		  		ans[2].push_back(a[i].Y);
		  		ans[0].push_back(a[i].Y);
			  	ans[1].push_back(a[i].Y);
		  		ans[2].push_back(a[i+1].Y);
				break;
			}
			fir = 1;
		} else if (cnt >= 3) {
		  	ans[0].push_back(a[i].Y);
		  	ans[1].push_back(a[i+1].Y);
		  	ans[2].push_back(a[i+2].Y);
		  	ans[0].push_back(a[i+1].Y);
		  	ans[1].push_back(a[i+2].Y);
		  	ans[2].push_back(a[i].Y);
		  	ans[0].push_back(a[i+2].Y);
		  	ans[1].push_back(a[i].Y);
		  	ans[2].push_back(a[i+1].Y);
			j = min(i + 3, j);
			break;
		}
		i = j - 1;
	}
	j = min(i + 3, j);
	for (i = j; i <= n; i++) {
		  	ans[0].push_back(a[i].Y);
		  	ans[1].push_back(a[i].Y);
		  	ans[2].push_back(a[i].Y);
	}
	for (int i = 0; i < 3; i++) {
	  	for (int j = 0; j < n; j++) {
		  	printf("%d%c", ans[i][j], j == n-1 ? '\n' : ' ');
		}
	}
	return 0;
}
