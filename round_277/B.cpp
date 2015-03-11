/*************************************************************************
    > File Name: B.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年11月11日 星期二 23时13分48秒
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

int m, n;
int b[105][105], a[105][105];
int row[105], col[105];

int main(void) {
  	cin >> n >> m;	
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
		cin >> b[i][j];
		row[i] += b[i][j];
		col[j] += b[i][j];
	}
	bool flag = true;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
	  	if (b[i][j]) {
		  	if (row[i] != m && col[j] != n) {
			  	flag = false;
				break;
			}
			if (row[i] == m && col[j] == n)
				a[i][j] = 1;
		}
	}
	if (!flag) cout << "NO\n";
	else {
	  	cout << "YES\n";
	  	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
		  	cout << a[i][j] << (j == m ? '\n' : ' ');
		}
	}

	return 0;
}
