/*************************************************************************
    > File Name: C.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年11月17日 星期一 23时44分08秒
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

int main(void) {
  	ios::sync_with_stdio(false);
  	int m, s;
	cin >> m >> s;
	if (s == 0) {
	  	if (m != 1) cout << "-1 -1" << endl;
		else cout << 0 << ' ' << 0 << endl;
		return 0;
	}
	if (m == 1) {
	  	if (s > 9) cout << "-1 -1" << endl;
		else cout << s << ' ' << s << endl;
		return 0;
	}
	int digit[105], sum = 0, flag = 1;
	for (int i = 0; i < m; i++) {
	  	for (int j = flag; j < 10; j++) if (sum + j + (m - i - 1) * 9 >= s) {
		  	flag = 0;
			digit[i] = j;
			sum += j;
			break;
		}
	}
	if (sum != s) {
		cout << "-1 - 1\n"; 
		return 0;
	}
	for (int i = 0; i < m; i++) cout << digit[i];
	cout << ' ';
	flag = 1;
	sum = 0;
	for (int i = 0; i < m; i++) {
	  	for (int j = 9; j >= flag; j--) if (sum + j <= s) {
		  	flag = 0;
			digit[i] = j;
			sum += j;
			break;
		}
	}
	if (sum != s) {
		cout << "-1 - 1\n"; 
		return 0;
	}
	for (int i = 0; i < m; i++) cout << digit[i];
	cout << endl;
	return 0;
}
