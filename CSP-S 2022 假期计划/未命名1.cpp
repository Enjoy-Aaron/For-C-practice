#include <bits/stdc++.h>
#define r read()
#define MIN(a,b) (a<b? a:b)
#define MAX(a,b) (a>b? a:b)
using namespace std;
typedef unsigned long long ull;
const int N=2510,M=20010,INF=1e7;
struct Edges{
	int next;
	int to;
	Edges()
	{
		next=0;
		to=0;
	}
}edge[M];
int num_edge,head[N];
int n,m,k,sc[N],d[N];
bool v[N],vi[N];
ull src,msc;

inline int read()
{
	register int x=0;
	register char ch=getchar();
	while (ch<48 || ch>57) ch=getchar();
	while (ch>=48 && ch<=57) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x;
}

void add_edge(int from,int to)
{
	++num_edge;
	edge[num_edge].next=head[from];
	edge[num_edge].to=to;
	head[from]=num_edge;
}

int ti(int from,int to)
{
	int t=INF;
	for (int i=head[from];i!=0;i=edge[i].next)
	{
		if (edge[i].to==to) return 0;
		if (!vi[edge[i].to])
		{
			vi[edge[i].to]=1;
			t=MIN(t,ti(edge[i].to,to)+1);
			vi[edge[i].to]=0;
		}
	}
	return t;
}

void dfs(int dep)
{
	if (dep==5 && ti(d[dep],1)<=k)
	{
		msc=MAX(msc,src);
		return;
	}
	for (int i=2;i<=n;++i)
	{
		if (!v[i] && ti(d[dep],i)<=k)
		{
			d[dep+1]=i;
			v[i]=1;
			src+=sc[i];
			dfs(dep+1);
			v[i]=0;
			src-=sc[i];
		}
	}
}

int main()
{
	n=r;m=r;k=r;
	for (int i=2;i<=n;++i) sc[i]=r;
	for (int i=1;i<=m;++i)
	{
		int u=r,v=r;
		add_edge(u,v);
		add_edge(v,u);
	}
	d[1]=1;
	v[1]=1;
	dfs(1);
	printf("%llu",msc);
	return 0;
}
