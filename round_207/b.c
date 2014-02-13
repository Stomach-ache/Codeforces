#include <stdio.h>
#include <string.h>

int color[100005];

void func(int a, int b, int c){
	int vis[4];
	memset(vis, 0, sizeof(vis));
	if(color[a]){
		vis[color[a]] = 1;
	}
	if(color[b]){
		vis[color[b]] = 1;
	}
	if(color[c]){
		vis[color[c]] = 1;
	}
	int i;
	for (i = 1; i <= 3; i++){
		if (!vis[i]){
			if (!color[a]){
				color[a] = i;
			}
			else if (!color[b]){
				color[b] = i;
			}
			else if (!color[c]){
				color[c] = i;
			}
		}
	}
}

int main(void){
	int n, m;
	while (~scanf("%d %d", &n, &m)) {
		int i;
		memset(color, 0, sizeof(color));
		for (i = 0; i < m; i++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			func(a, b, c);
		}
		for (i = 1; i <= n; i++){
			printf("%d%c", color[i], i==n ? '\n' : ' ');
		}
	}
}
