#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
#define maxn 100005
vector<int> next[maxn];
int vis[maxn],dif[maxn];

int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i = 1; i < 100005; i++){
			next[i].clear();
		}
		memset(vis,0,sizeof(vis));
		memset(dif,0,sizeof(dif));
		for(int i = 1; i <= n; i++){
			int a;
			scanf("%d",&a);
			vis[a]++;
			next[a].push_back(i);
		}
		int t = 0;
		for(int i = 1; i <= 100000; i++){
			if(vis[i]){
				t++;
				if(vis[i] == 1){
					continue;
				}
				else{
					dif[i] = next[i][1] - next[i][0];
				}
				unsigned int j;
				for(j = 2; j < next[i].size(); j++){
					int res = next[i][j] - next[i][j-1];
					if(res != dif[i]){
						t--;
						vis[i] = 0;
						break;
					}
				}
			}
		}
		printf("%d\n",t);
		for(int i = 1; i <= 100000; i++){
			if(vis[i]){
				printf("%d %d\n",i,dif[i]);
			}
		}
	}
}
