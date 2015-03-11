/*************************************************************************
    > File Name: A.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年10月05日 星期日 21时18分33秒
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
  	int k;
	cin >> k;
	cout << "+------------------------+\n";
	bool flag = false;
	if (k >= 3) {
	  	flag = true;
		k--;
	}
	for (int i = 1; i <= 4; i++) {
	  	cout << '|';
		if (i == 3) {
		  	if (flag) {
			  	cout << 'O';
			} else {
			  	cout << '#';
			}
			for (int j = 0; j < 23; j++) 
			  	cout << '.';
			cout << "|\n";
			continue;
		} 
		for (int j = 1; j < 12; j++) {
		  	if ((j-1) * 3 + i - (i == 4 ? 1 : 0) <= k) cout << "O.";
			else cout << "#.";
		}
		if (i == 1) {
		  	cout << "|D";
		} else {
		  	cout << "|.";
		}
		cout << '|';
		if (i == 1 || i == 4) {
		  	cout << ')';
		}
		cout << '\n';
	}
	cout << "+------------------------+\n";

	return 0;
}
