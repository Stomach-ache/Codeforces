/*************************************************************************
    > File Name: C.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年05月15日 星期四 23时51分15秒
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

bool is_prime[100005];
int a[100005], pos[100005]; // hold the index of the value of i
typedef pair<int, int> pii;
vector<pii> ans; // keep each move...

void 
init() {
  	memset(is_prime, true, sizeof(is_prime));
	is_prime[1] = false;
	for (int i = 2; i < 1000; i++) {
	  	if (is_prime[i]) {
		  	for (int j = i*i; j < 100002; j += i) {
			  	is_prime[j] = false;
			}
		}
	}
	return ;
}

int
main(void) {
  	init();
  	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
	  	scanf("%d", a + i);
		pos[a[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
	  	if (i == a[i]) continue;
		if (is_prime[pos[i]-i+1]) {
			swap(a[i], a[pos[i]]);
			ans.push_back(pii(pos[i], i));
			pos[a[pos[i]]] = pos[i];
		  	pos[i] = i;
		} else {
		  	// distance from index i to pos[i]
		  	int d = pos[i] - i;
			// in other words, a[i] will be equal to i when d equals 0
			while (d) {
		  		for (int k = d; k >= 1; k--) {
				  	if (is_prime[k+1]) {
					  	// from index of i+d-k to index of pos[i]
						swap(a[i+d-k], a[pos[i]]);
						// push to ans
						ans.push_back(pii(i+d-k, pos[i]));
						// update pos[]
						pos[a[pos[i]]] = pos[i];
						pos[i] = i+d-k;
						// update d
						d -= k;
						break;
					}
				}
			}
		}
	}
//	for (int i = 1; i <= 10; i++) {
//	  	cout << a[i] << ' ';
//	}
//	cout << endl;
	int len = ans.size();
	printf("%d\n", len);
	for (int i = 0; i < len; i++) {
	  	if (ans[i].first > ans[i].second) {
		  	swap(ans[i].first, ans[i].second);
		}
	  	printf("%d %d\n", ans[i].first, ans[i].second);
	}

	return 0;
}
