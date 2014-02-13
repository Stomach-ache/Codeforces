#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define Max(x,y) (x>y?x:y)
#define max 5000+5

char map[max][max], a[max][max];
int dp[max],temp[max],n,m;

int DP(){
    int res=0;
    memcpy(temp,dp,sizeof(dp));
    sort(temp+1,temp+m+1);
    for(int i=m;i>=1;i--){
        if(temp[i]){
            res=Max(res,temp[i]*(m-i+1));
        }
    }
    return res;
}

int main(){
    while(~scanf("%d %d",&n,&m)){
        int ans=0;
        memset(dp,0,sizeof(dp));
	for(int i = 1; i <= n; i++) 
		scanf("%s", a[i] + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			map[j][i] = a[i][j];
		}
	}
	int tmp = n;
	n = m;
	m = tmp;
        for(int i=1;i<=n;i++){
            //scanf("%s",map[i]+1);
            for(int j=1;j<=m;j++){
                if(map[i][j]=='1'){
                    dp[j]++;
                }
                else{
                    dp[j]=0;
                }
            }
            ans=Max(ans,DP());
        }
        printf("%d\n",ans);
    }
}

