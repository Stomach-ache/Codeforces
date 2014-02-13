#include <iostream>
#include <string>

using namespace std;

int v, a[10];

int main() {
	while (cin >> v) {
		int min = 1000000, min_i;
		for (int i=1; i<=9; i++) {
			cin >> a[i];
			if (a[i] < min) {
				min = a[i];
				min_i = i;
			}
		}

		int cnt = v/min;
		v -= cnt*min;

		string res;
		for (int i=0; i<cnt; i++)
			res += min_i+'0';

		for (unsigned int i=0; i<res.size(); i++) {
			for (int j=9; j>=min_i; j--) {
				if (v+min >= a[j]) {
					res[i] = j+'0';
					v -= a[j]-min;
					break;
				}
			}
		}

		if (cnt == 0) 
			cout << "-1\n";
		else
			cout << res << '\n';
	}

	return 0;
}
