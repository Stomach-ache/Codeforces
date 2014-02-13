#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int a[105],b[105],n,m;

int main(){
	while(~scanf("%d%d",&n,&m)){
		for(int i = 0; i < n; i++){
			scanf("%d",&a[i]);
		}
		for(int i =0; i < m; i++){
			scanf("%d",&b[i]);
		}
		sort(a,a+n);
		sort(b,b+m);
		int ans = 0, cnt = 0;
		for(int i = a[n-1]; i < b[0]; i++){
			if(a[0] * 2 > i){
				continue;
			}
			ans = i; cnt = 1; break;
		}
		if(cnt == 0){
			puts("-1");
		}
		else{
			printf("%d\n",ans);
		}
	}
}
