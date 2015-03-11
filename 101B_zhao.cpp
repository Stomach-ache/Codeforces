/*************************************************************************
    > File Name: 101B_zhao.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年07月19日 星期六 13时24分45秒
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
int n,m,c[100005],b[100005],e[100005],dp[100005];
int lowbit(int x)
{
  return x&-x;
}
int sum(int x)
{
  int ret=0;
  while (x>0)
  {
	ret=(c[x]%1000000007+ret%1000000007)%1000000007;
	x-=lowbit(x);
  }
  return ret;
}
void add(int x,int d)
{
  while (x<=m+1)
  {
	c[x]=(d%1000000007+c[x]%1000000007)%1000000007;
	x+=lowbit(x);
  }
}
void mysort(int l,int r)
{
  int i=l,j=r,x=e[(i+j)/2],y,x1=b[(i+j)/2];
  while (i<=j)
  {
	while (e[i]<x||(e[i]==x&&b[i]>x1)) i++;
	while (e[j]>x||(e[j]==x&&b[j]<x1)) j--;
	if (i<=j)
	{
	  y=e[i]; e[i]=e[j]; e[j]=y;
	  y=b[i]; b[i]=b[j]; b[j]=y;
	  i++; j--;
	}
  }
  if (l<j) mysort(l,j);
  if (i<r) mysort(i,r);
}
int search(int l,int r,int x)
{
  if (x>e[r]) return -1;
  if (x<=e[l]) return l;
  if (l+1==r) return r;
  int mid=(l+r)/2;
  if (x<=e[mid]) return search(l,mid,x);
  else return search(mid+1,r,x);
}
int main()
{
  int i,x;
  scanf("%d%d",&n,&m);
  b[1]=0; e[1]=0;
  for (i=1;i<=m;i++)
	scanf("%d%d",&b[i+1],&e[i+1]);
  memset(c,0,sizeof(c));
  mysort(2,m+1);
  dp[1]=1;
  add(1,1);
  for (i=2;i<=m+1;i++)
	if (e[i-1]!=e[i]||b[i]!=b[i-1])
  {
	x=search(1,i-1,b[i]);
	if (x==-1) dp[i]=0;
	else dp[i]=(sum(i-1)-sum(x-1))%1000000007;
	add(i,dp[i]);
  }
  x=m+1;
  while (e[x]==e[x-1]&&b[x]==b[x-1]) x--;
  if (e[x]==n) printf("%d\n",dp[x]);
  else printf("0\n");
}






