#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a, b, c;

int main(void) {
	while (~scanf("%d %d %d", &a, &b, &c)) {
		if (a==0 && b==0 && c==0)
			puts("-1");
		else if (a==0 && b==0 && c!=0)
			puts("0");
		else if (a==0 && b!=0) {
			puts("1");
			printf("%.6lf\n", -c*1.0/b);
		}
		else {
			long long d = (long long)b*b-4*(long long)a*c;
			if (d < 0) {
				puts("0"); continue;
			}
			if (d == 0) {
				puts("1");
				printf("%.6lf\n", (-b+0.0)/(2.0*a));
				continue;
			}
			double x1 = (-b+sqrt(d+0.0))/(2*a);
			double x2 = (-b-sqrt(d+0.0))/(2*a);

			puts("2");
			if (x1 > x2)
				swap(x1, x2);
			printf("%.6lf\n%.6lf\n", x1, x2);
		}
	}

	return 0;
}
