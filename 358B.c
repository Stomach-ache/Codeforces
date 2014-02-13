#include <stdio.h>
#include <string.h>

int n, sum[100005];
char str[100005], str2[100005], tmp[100005];

int main(void){
	while (~scanf("%d", &n)) {
		str[0] = '\0';
		sum[0] = 0;
		int i, j, len2;
		for (i=1; i<=n; i++) {
			scanf("%s", tmp);
			sum[i] = sum[i-1]+strlen(tmp);
			strcat(str, tmp);
		}
		scanf("%s", str2);
		len2 = strlen(str2);
		i = j = 0;
		int cnt = 0, cnt2 = 0;
		for (; j<len2; j++) {
			if (str2[j] == '<') {
				while (str2[j]!='3' && j<len2)
					j++;
				if (j!=len2)
					cnt2++;
				while (i<sum[cnt+1] && j<len2) {
					if (str[i] == str2[j])
						i++;
					j++;
				}
				if (i == sum[cnt+1]) {
					cnt++;
					j--;
				}
			}	
		}

		if (cnt==n && cnt2==n+1)
			puts("yes");
		else
			puts("no");
	}

	return 0;
}
