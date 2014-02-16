#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N (1000000+5)

int n, p, a[MAX_N], vis[MAX_N];

int cmp(const void *x, const void *y)
{
    return *(int*)x - *(int*)y;
}

int main(void)
{
    while (~scanf("%d %d", &n, &p))
    {
        int i, j;
        for (i = 0; i < n; i++) scanf("%d", a+i);
        qsort(a, n, sizeof(int), cmp);
        int ans = 0;
        memset(vis, 0, sizeof(vis));
        for (i = 0, j = n-1; i < j; i++) if ( !vis[i] )
        {
            if (a[i] + a[j] == p)
            {
                ans++;
                vis[i] = vis[j--] = 1;
            }
            else if (a[i] + a[j] > p) j--, i--;
        }
        printf("%d\n", ans);
    }

    return 0;
}
