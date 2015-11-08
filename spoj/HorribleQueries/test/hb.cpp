#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;

struct node
{
	LL ans;
	LL pro;
};

node *segtree;

LL query(int idx, int b, int e, int qb, int qe)
{
	if (b > qe || qb > e)
		return 0;
	if (segtree[idx].pro > 0)
	{
		segtree[idx].ans += (LL)(e-b+1)*segtree[idx].pro;
		if (b != e)
		{
			segtree[2*idx+1].pro += segtree[idx].pro;
			segtree[2*idx+2].pro += segtree[idx].pro;
		}
		segtree[idx].pro = 0;
	}
	if (b >= qb && e <= qe)
		return segtree[idx].ans;
	int mid = (b+e)>>1;
	LL ansL = query(2*idx+1, b, mid, qb, qe);
	LL ansR = query(2*idx+2, mid+1, e, qb, qe);
	return ansL+ansR;
}

void update(int idx, int b, int e, int qb, int qe, LL v)
{
	if (b > qe || qb > e)
		return;
	if (segtree[idx].pro > 0)
	{
		segtree[idx].ans += (LL)(e-b+1)*segtree[idx].pro;
		if (b != e)
		{
			segtree[2*idx+1].pro += segtree[idx].pro;
			segtree[2*idx+2].pro += segtree[idx].pro;
		}
		segtree[idx].pro = 0;
	}
	if (b >= qb && e <= qe)
	{
		segtree[idx].pro = v;
		return;
	}
	segtree[idx].ans += (LL)(min(e, qe)-max(b, qb)+1)*v;
	int mid = (b+e)>>1;
	update(2*idx+1, b, mid, qb, qe, v);
	update(2*idx+2, mid+1, e, qb, qe, v);
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		int N, Q;
		scanf("%d %d", &N, &Q);
		segtree = new node[4*N];
		for (int i = 0; i < 4*N; i++)
		{
			segtree[i].ans = 0;
			segtree[i].pro = 0;
		}
		int c, p, q;
		LL v;
		for (int i = 0; i < Q; i++)
		{
			scanf("%d %d %d", &c, &p, &q);
			if (c == 0)
			{
				scanf("%lld", &v);
				update(0, 0, N-1, p-1, q-1, v);
			}
			else
				printf("%lld\n", query(0, 0, N-1, p-1, q-1));
			for(int j=0;j<4*N;j++)
			  printf("%-5lld ", segtree[j].ans);
			printf("\n");
		}
	}
	return 0;
}
