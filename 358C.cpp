#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vec;

int main() {
	int n;
	while (cin >> n) {
		vec table[3];
		while (n--) {
			int a;
			cin >> a;
			if (a) {
				int flag = 0;
				for (int i=0; i<3; i++) {
					if (table[i].empty()) {
						if (i == 0) {
							flag = 1;
							puts("pushStack");
						}
						else if (i == 1) {
							flag = 1;
							puts("pushQueue");
						}
						else {
							flag = 1;
							puts("pushFront");
						}
					}
				}
				if (!flag) {
					if (table[2].size() == 1) {
						vector
					}
				}
			}
		}
	}
}
