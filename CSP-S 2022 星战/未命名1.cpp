#include <bits/stdc++.h>
#define r read()
using namespace std;
const int N=5e5+10;
int n,m,q;
struct Edges{
	int next;
	int from;
	int to;
	int bro;
	Edges()
	{
		next=0;
		from=0;
		to=0;
		bro=0;
	}
}edge[N];
int head[N],num_edge;
int ougt[N];

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
	edge[num_edge].from=from;
	edge[num_edge].to=to;
	head[from]=num_edge;
	ougt[from]++;
}

void solve(int type)
{
	int u,v;
	switch(type)
	{
		case 1:
			u=r;v=r;
			for (int i=head[u];i!=0;i=edge[i].next)
				if (edge[i].to==v && edge[i].bro==0)
				{
					edge[i].bro=1;
					ougt[u]--;
					break;
				}
			break;
		case 2:
			u=r;
			for (int i=1;i<=num_edge;++i)
				if (edge[i].to==u && edge[i].bro==0)
				{
					edge[i].bro=1;
					ougt[edge[i].from]--;
				}
			break;
		case 3:
			u=r;v=r;
			for (int i=head[u];i!=0;i=edge[i].next)
				if (edge[i].to==v && edge[i].bro==1)
				{
					edge[i].bro=0;
					ougt[u]++;
					break;
				}
			break;
		case 4:
			u=r;
			for (int i=1;i<=num_edge;++i)
				if (edge[i].to==u && edge[i].bro==1)
				{
					edge[i].bro=0;
					ougt[edge[i].from]++;
				}
			break;
	}
}

bool oug1()
{
	for (int i=1;i<=n;++i)
		if (ougt[i]!=1) return false;
	return true;
}

int main()
{
	n=r;m=r;
	for (int i=1;i<=m;++i)
	{
		int from=r,to=r;
		add_edge(from,to);
	}
	q=r;
	while (q--)
	{
		int type=r;
		solve(type);
		if (oug1()) puts("YES");
		else puts("NO");
	}
	return 0;
}
