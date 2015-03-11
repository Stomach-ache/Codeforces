/*************************************************************************
    > File Name: A.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年10月19日 星期日 17时05分53秒
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
vector<pii> arr;

int main(void) {
  	ios::sync_with_stdio(false);
  	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
	  	int a, b;
		cin >> a >> b;
		arr.push_back(pii(a, b));
	}
	sort(arr.begin(), arr.end());
	int res = arr[0].second;
	for (int i = 1; i < n; i++) {
	  	if (arr[i].second < res) res = arr[i].first;
		else res = arr[i].second;
	}
	cout << res << endl;
	return 0;
}
