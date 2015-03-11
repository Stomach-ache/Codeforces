/*************************************************************************
    > File Name: A.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年09月26日 星期五 23时33分44秒
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

int a[7], cnt[10];

int main(void) {
  	ios::sync_with_stdio(false);
  	for (int i = 1; i <= 6; i++) cin >> a[i], cnt[a[i]]++;
	bool flag = 0;
	int h, b;
	for (int i = 1; i <= 9; i++) if (cnt[i] >= 4) {
	  	flag = 1;		
	}
	h = b = -1;
	for (int i = 1; i <= 9; i++) {
	  	if (cnt[i] > 4) cnt[i] -= 4; 
		if (cnt[i] && h == -1) {
		  h = i;
		  cnt[i]--;
		}	
		if (cnt[i] && b == -1) b = i;
	}
	if (!flag) cout << "Alien" << endl;
	if (flag && h == b) cout << "Elephant" << endl;
	if (flag && h != b)cout << "Bear" << endl;

	return 0;
}
