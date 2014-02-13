#include<stdio.h>
#include<string.h>
#include<math.h>
#define eps 1e-9
#define inf 0x3f3f3f3f
#define min(x,y) ((x)<(y)?(x):(y))

int main(){
	int n;
	while(~scanf("%d",&n)){
		double sum = 0.0;
		int cnt = 0;
		for(int i = 0; i < n+n; i++){
			double a;
			scanf("%lf",&a);
			if(fabs(a - (int)a) <= eps){
				cnt++;
			}
			sum += fabs(a - (int)a);
		}
		double ans = inf;
		for(int i = n-cnt; i <= n; i++){
			ans = min(ans,fabs(sum-i));
		}
		printf("%.3lf\n",ans);
	}
}
