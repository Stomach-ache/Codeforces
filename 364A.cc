#include <iostream>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
using namespace std;

char s[4005];
int a, sum[4005], cnt[36005];
typedef long long ll;

ll getval(int v) {
	if (v > 36000)
		return 0;

	return cnt[v];
}

int main() {
	while (cin >> a) {
		cin >> s;
		sum[0] = 0;
		int len = strlen(s);
		memset(cnt, 0, sizeof(cnt));
		for (int i=0; i<len; i++)
			sum[i+1] = sum[i]+(s[i]-'0');

		for (int i=1; i<=len; i++)
			for (int j=0; j<i; j++)
				cnt[sum[i]-sum[j]]++;
		ll ans = 0;
		if (a == 0) {
			for (int i=0; i<=36000; i++)
				ans += cnt[i];
			ans *= cnt[0]*2;
			ans -= (ll)cnt[0]*cnt[0];
		}
		else {
			for (int i=1; i<=36000; i++) {
				if (a%i)
					continue;
				ans += (ll)cnt[i]*getval(a/i);
			}
		}
		cout << ans <<"\n";
	}

	return 0;
}
