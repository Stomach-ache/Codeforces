/*************************************************************************
    > File Name: d.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年11月06日 星期四 21时21分10秒
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

const int MAX_N = 200050;
bool calc[MAX_N * 5];

int main(void) {
  	ios::sync_with_stdio(false);
  	int n, mmax = 0;	
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; i++) {
	  	int x;
		cin >> x;
		mmax = max(mmax, x);
		arr.push_back(x);
	}

	sort(arr.begin(), arr.end());
	int res = 0;
	for (int i = 0; i < n - 1; i++) {
	  	if (calc[arr[i]]) continue;
		if (arr[i] == 1) continue;
		int x = arr[i];
		calc[x] = true;
		while (x <= mmax) {
		  	x += arr[i];
		  	int pos = lower_bound(arr.begin(), arr.end(), x) - arr.begin() - 1;
			res = max(res, arr[pos] % arr[i]);
		}
	}
	cout << res << endl;

	return 0;
}
