/*************************************************************************
    > File Name: C.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年10月07日 星期二 00时17分28秒
    > Propose: 
 ************************************************************************/
#include <set>
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

struct node {
  	int x, y, a, b;
}p[5];

typedef pair<int, int> pii;
#define X first
#define Y second

void rotate(const node &s, pii &res) {
  	res.X = s.a - (s.y - s.b);	
	res.Y = s.b + (s.x - s.a);
}

int dist(const node &s, const node &t) {
  	return (s.x - t.x) * (s.x - t.x) + (s.y - t.y) * (s.y - t.y);
}

bool ok() {
  	set<int> seg;
	if (seg.find(dist(p[1], p[2])) == seg.end()) {
	  	seg.insert(dist(p[1], p[2]));	
	}
	if (seg.find(dist(p[1], p[3])) == seg.end()) {
	  	seg.insert(dist(p[1], p[3]));	
	}
	if (seg.find(dist(p[1], p[4])) == seg.end()) {
	  	seg.insert(dist(p[1], p[4]));	
	}
	if (seg.find(dist(p[3], p[2])) == seg.end()) {
	  	seg.insert(dist(p[3], p[2]));	
	}
	if (seg.find(dist(p[4], p[2])) == seg.end()) {
	  	seg.insert(dist(p[4], p[2]));	
	}
	if (seg.find(dist(p[3], p[4])) == seg.end()) {
	  	seg.insert(dist(p[3], p[4]));	
	}
	if (seg.size() != 2) return false;
	int a[3], cnt = 1;
	for (set<int>::iterator it = seg.begin(); it != seg.end(); it++) {
	  	a[cnt++] = *it;	
	}
	if (a[1] == 0 || a[2] == 0) return false;
	if (a[1] > a[2]) swap(a[1], a[2]);
	return a[2] == 2 * a[1];
}

int main(void) {
  	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	pii f;
	for (int i = 1; i <= n; i++) {
	  	for (int j = 1; j <= 4; j++) {
		  	cin >> p[j].x >> p[j].y >> p[j].a >> p[j].b;	
		}
			bool flag = false;
			int ans = 100000;
			for (int k1 = 0; k1 < 4; k1++) {
			  	for (int k2 = 0; k2 < 4; k2++) {
				  	for (int k3 = 0; k3 < 4; k3++) {
					  	for (int k4 = 0; k4 < 4; k4++) {
							if (ok()) {
							  	flag = true;
								ans = min(ans, k1 + k2 + k3 + k4);
							}
							rotate(p[4], f);
							p[4].x = f.X;
							p[4].y = f.Y;
						}
						rotate(p[3], f);
						p[3].x = f.X;
				  		p[3].y = f.Y;
					}
					rotate(p[2], f);
					p[2].x = f.X;
					p[2].y = f.Y;
				}
				rotate(p[1], f);
				p[1].x = f.X;
				p[1].y = f.Y;
			}
		if (flag) cout << ans << endl;
		else cout << "-1" << endl;
	}

	return 0;
}
