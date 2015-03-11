/*************************************************************************
    > File Name: C.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年08月30日 星期六 15时54分42秒
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

int n, a[2002][2002];
typedef long long LL;
LL sum[2002][2002], sum2[2002][2002];

int main(void) {
  	ios::sync_with_stdio(false);
	cin >> n;
	//memset(sum, 0, sizeof(sum));
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> a[i][j];
	for (int i = 1; i <= n; i++) {
	  	for (int j = n; j >= 1; j--) {
		  	sum[i][j] += a[i][j];
			if (i - 1 >= 1 && j - 1 >= 1) 
			  	sum[i][j] += sum[i - 1][j - 1];
		}
	}
	for (int i = n-1; i >= 1; i--) {
	  	for (int j = n-1; j >=1; j--) {
		  	sum[i][j] = sum[i + 1][j + 1];
		}
	}
	for (int i = 1; i <= n; i++) {
	  	for (int j = 1; j <= n; j++) {
		  	sum2[i][j] += a[i][j];
		  	if (i - 1 >= 1 && j + 1 <= n) {
			  	sum2[i][j] += sum2[i - 1][j + 1];
			}
		}
	}
	for (int i = n-1; i >= 1; i--) {
	  	for (int j = 2; j <= n; j++) {
		  	sum2[i][j] = sum2[i + 1][j - 1];
		}
	}
	int x1, y1, x2, y2;
	LL num1 = -1, num2 = -1;
	for (int i = 1; i <= n; i++) {
	  	for (int j = 1; j <= n; j++) {
		  	if ((i + j) % 2 == 0 && num1 < sum[i][j] + sum2[i][j] - a[i][j]) {
			  	num1 = sum[i][j] + sum2[i][j] - a[i][j];
				x1 = i; y1 = j;
			} 
			if ((i + j) % 2 == 1 && num2 < sum[i][j] + sum2[i][j]-a[i][j]) {
			  	num2 = sum[i][j] + sum2[i][j] - a[i][j];
				x2 = i; y2 = j;
			}
		}
	}
	cout << num1 + num2 << endl;
	cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;

	return 0;
}
