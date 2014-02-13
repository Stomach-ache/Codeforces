#include<stdio.h>
#include<string.h>

int fa[100005],rank[100005],a[100005],type[100005],cnt[100005],n;

int findset(int x){
	return x != fa[x] ? fa[x] = findset(fa[x]) : x;
}

void print_path(int s){
	if(a[s] == 0 || cnt[a[s]] > 1){
		printf("%d",s);
		return;
	}
	print_path(a[s]);
	printf(" %d",s);
}

int main(){
	while(~scanf("%d",&n)){
		memset(cnt,0,sizeof(cnt));
		for(int i = 1; i <= n; i++){
			fa[i] = i;
			rank[i] = 1;
			scanf("%d",&type[i]);
		}
		for(int i = 1; i <= n; i++){
			scanf("%d",&a[i]);
			cnt[a[i]]++;
		}
		for(int i = 1; i <= n; i++){
			if(cnt[i] >= 2 || cnt[a[i]] >= 2){
				continue;
			}
			if(a[i] == 0){
				continue;
			}
			int x = findset(i);
			int y = findset(a[i]);
			if(x != y){
				fa[x] = y;
				rank[y] += rank[x];
			}
		}
		int ans = 0, s;
		for(int i = 1; i <= n; i++){
			if(type[i]){
				if(ans < rank[findset(i)]){
					ans = rank[findset(i)];
					s = i;
				}
			}
		}
		printf("%d\n",ans);
		print_path(s);
		puts("");
	}
}
