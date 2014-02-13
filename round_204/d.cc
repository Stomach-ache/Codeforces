#include<stdio.h>
#include<string.h>
int a[3005];

int main(){
	int n, cnt = 0;
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&a[i]);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			if(a[j] > a[i])cnt++;
		}
	}
	if(cnt==0 || cnt==1){
		printf("%d.000000\n",cnt);
	}
}
