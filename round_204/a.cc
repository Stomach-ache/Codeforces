#include<stdio.h>
#include<string.h>

int main(){
	int cnt_0,cnt_5,n;
	while(~scanf("%d",&n)){
		cnt_0 = cnt_5 = 0;
		for(int i = 0; i < n; i++){
			int a;
			scanf("%d",&a);
			if(a == 0){
				cnt_0++;
			}
			else{
				cnt_5++;
			}
		}
		if(cnt_0 == 0){
			puts("-1");
			continue;
		}
		if(cnt_5 == 0){
			puts("0");
			continue;
		}
		int res = cnt_5 * 5;
		while(res % 9 != 0){
			res -=5;
			cnt_5--;
		}
		if(cnt_5 > 0){
			for(int i = 0; i < cnt_5; i++){
				printf("5");
			}
			for(int i = 0; i < cnt_0; i++){
				printf("0");
			}
			puts("");
		}
		else{
			puts("0");
		}
	}
}
