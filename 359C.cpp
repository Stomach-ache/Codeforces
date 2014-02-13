#include <cstdio>
#include <set>
using namespace std;

#define min(x, y) ((x)<(y)?(x):(y))
#define mod 1000000007
typedef long long ll;

ll a[100005], n, x;

ll pow_mod(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b&1) {
			ans = (ans*a)%mod;
		}
		b >>= 1;
		a = (a*a)%mod;
	}

	return ans;
}

int main(void) {
	while (~scanf("%lld %lld", &n, &x)) {
		multiset<ll> my_set;
		ll i, sum = 0;
		for (i=1; i<=n; i++) {
			scanf("%lld", &a[i]);
			sum += a[i];
		}
		for (i=1; i<=n; i++)
			my_set.insert(sum-a[i]);
		multiset<ll>::iterator it;
		for (it=my_set.begin(); it!=my_set.end(); it++) {
			if (my_set.count((*it)) == x) {
				my_set.insert((*it)+1);
				my_set.erase((*it));
			}
		}
		printf("%lld\n", pow_mod(x, m));
	}

	return 0;
}

