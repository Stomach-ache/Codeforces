/*************************************************************************
    > File Name: zhao.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年07月18日 星期五 00时41分27秒
    > Propose: 
 ************************************************************************/

#include <cmath>
#include <string>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int a[5005];
int dfs(int p,int q)
{
  int f1,f2,i,min=0x3f3f3f3f;
  if (p==q) return 1;
  for (i=p;i<=q;i++)
	if (a[i]<min) min=a[i];
  if (min>=q-p+1) return q-p+1;
  for (i=p;i<=q;i++) a[i]-=min;
  int q1=q,p1=p;
  while (a[p]==0) p++;
  while (a[q]==0) q--;
  if (p>q) return min;
  f1=p; f2=q;
  for (i=p;i<q;i++)
	if (a[i]==0&&a[i-1]!=0) min+=dfs(f1,i-1);
    else if (a[i]!=0&&a[i-1]==0) f1=i;
  if (a[f2-1]==0) min+=1; else min+=dfs(f1,f2);
  if (min>q1-p1+1) return q1-p1+1; else return min;
}
int main()
{
  int n,i;
  scanf("%d",&n);
  for (i=1;i<=n;i++) scanf("%d",&a[i]);
  printf("%d\n",dfs(1,n));
}
