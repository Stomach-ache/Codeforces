/*************************************************************************
    > File Name: 242C.cpp
    > Author: Stomach_ache
    > Mail: 1179998621@qq.com 
    > Created Time: 2014年01月08日 星期三 11时44分46秒
 ************************************************************************/
//by Wei Tong
#include <algorithm>
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#include <map>

using namespace std;

int dx[] = {1, 1, 1, -1, -1, -1, 0, 0};
int dy[] = {-1, 0, 1, -1, 0, 1, -1, 1};

typedef pair<int, int> pii;
#define MK make_pair
#define X first
#define Y second

int main(void) {
		int x0, y0, x1, y1, n, r, a, b;
		while (~scanf("%d %d %d %d", &x0, &y0, &x1, &y1)) {
				scanf("%d", &n);
				//allowed cells
				set<pii> ok;
				//keep distance
				map<pii, int> dis;
				//the total number of points doesn't exceed 10^5
				while (n--) {
						scanf("%d %d %d", &r, &a, &b);
						for ( int i = a; i <= b; i++ )
							ok.insert(pii(r, i));
				}
				queue<pii> q;
				q.push(pii(x0, y0));
				dis[pii(x0, y0)] = 0;
				//BFS
				while ( !q.empty() ) {
						int x = q.front().X;
						int y = q.front().Y;
						int d = dis[pii(x, y)];
						q.pop();
						for ( int i = 0; i < 8; i++ ) {
								pii next = pii(x+dx[i], y+dy[i]);
								if ( dis.count(next) )
										continue;
								if ( !ok.count(next) )
										continue;
								dis[next] = d + 1;
								q.push(next);
						}
				}
				if ( !dis.count(pii(x1, y1)) )
					puts("-1");
				else
					printf("%d\n", dis[pii(x1, y1)]);
		}

		return 0;
}
