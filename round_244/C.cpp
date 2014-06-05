/*************************************************************************
    > File Name: C.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年05月03日 星期六 00时07分43秒
    > Propose: 
 ************************************************************************/
//#pragma comment(linker,"/STACK:102400000,102400000")
#include <algorithm>
#include <iostream>
//#include <fstream>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <queue>
#include <stack>
#include <cmath>
#include <list>
#include <set>
#include <map>
#define sf scanf
#define pf printf
#define fst first
#define scd second
#define pb push_back
#define mkp make_pair
#define scaf2(x,y) scaf(x);scaf(y);
#define scaf3(x,y,z) scaf(x);scaf(y);scaf(z);
#define cls(a,x) memset(a,x,sizeof a)
#define dt(x) cout<<#x<<"="<<x<<" ";
#define dte(x) cout<<#x<<"="<<x<<endl;

typedef __int64 LL;
typedef unsigned long long ULL;

using namespace std;
template<class T>inline void scaf(T &v)
{
    char ch;
		for(ch=getchar();ch>'9' || ch<'0';ch=getchar());v=ch-'0';
    for(ch=getchar();ch<='9' && ch>='0';ch=getchar()) v=(v<<1)+(v<<3)+ch-'0';
}

typedef pair<LL,int > PII;
const int MV=(int)1e5+5;
const int ME=311111;
const LL mod=(LL)1e9+7;
const double eps=1e-8;

LL org[MV];
/**************/
struct Edge_t{
	int to,next;
}edge[ME];
LL head[MV],et;
LL dfn[MV];/戳
LL low[MV];//到达当前点最少时间
LL tot;//totol 深度
LL instk[MV];//In Stack?1:0;//hash此点已入栈？
LL stk[MV],top;//栈
LL belong[MV];//某点属于哪个连通块
LL ans[MV];
int scc;/连通的总数目
vector<int>vc[MV];
int _cnt[MV];

inline void adde(LL u,LL v){
	edge[et].to=v,edge[et].next=head[u],head[u]=et++;
}

inline void Init(){
	cls(belong,-1);cls(low,0);cls(head,-1);cls(dfn,-1);scc=et=top=0;
}

void Tarjan(int u){
	int e,v;
	dfn[u]=low[u]=++tot;
	instk[u]=true;
	stk[top++]=u;
	for(e=head[u];e!=-1;e=edge[e].next){
		if(dfn[v=edge[e].to]<0){
			Tarjan(v);
			low[u]>low[v]?low[u]=low[v]:0;
		}else if(instk[v])
			low[u]>dfn[v]?low[u]=dfn[v]:0;
	}//for
	if(dfn[u]==low[u]){
		scc++;
		do{//do while
			v=stk[--top];
			instk[v]=false;
			belong[v]=scc;
		}while(u!=v);//while
	}
}

inline void solve(LL n){
	LL i;
	for(i=1;i<=n;++i)
		if(dfn[i]<0) Tarjan(i);
}

/**************/

inline void task()
{
	int i,j,k,n,m;
	int u,v;
	Init();
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		//scaf(org[i]);
		scanf("%I64d",&org[i]);
		vc[i].clear();
		ans[i]=(LL)INT_MAX;
	}
	scanf("%d",&m);
	for(i=0;i<m;++i)
	{
		scanf("%d%d",&u,&v);
		adde(u,v);
	}
	solve(n);
	for(i=1;i<=n;++i)
	{
//		dte(org[i]);
		//printf("%I64d\n",org[i]);
		//printf("%I64d\n",belong[i]);
		ans[belong[i]]=min(ans[belong[i]],org[i]);
		vc[belong[i]].push_back(i);
	}
//	puts("");
	LL result=0;
	for(i=1;i<=scc;++i)
	{
		result=result+ans[i];
		int sz=vc[i].size();
		int cnt=0;
//		pf("%I64d ",ans[i]);
		for(j=0;j<sz;++j)
		{
			if(org[vc[i][j]]==ans[i])
				++cnt;
//			pf("%d ",vc[i][j]);
		}
//		puts("");
		_cnt[i]=cnt;
	}
	LL rb=1;
	for(i=1;i<=scc;++i)
	{
		rb=rb*_cnt[i]%mod;
	}
	pf("%I64d %I64d\n",result,rb);
}

int main()
{
	task();
	return 0;
}
