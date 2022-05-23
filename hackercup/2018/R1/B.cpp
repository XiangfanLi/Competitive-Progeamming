
#include <bits/stdc++.h>


using namespace std;


int N;
#define MAXN 2010
int A[MAXN];
int B[MAXN];
int L[MAXN];
int T;
int K;

int color[MAXN];

void pre(vector<int>& ret, int u)
{
	ret.push_back(u);
	if(A[u] != 0)
		pre(ret, A[u]);
	if(B[u] != 0)
		pre(ret, B[u]);
	return;
}

void post(vector<int>& ret, int u)
{
	if(A[u] != 0)
		post(ret, A[u]);
	if(B[u] != 0)
		post(ret, B[u]);
	ret.push_back(u);
	return;
}

int find(int u)
{
	int x = u;
	while(color[u] != u)
	{
		u = color[u];
	}
	while(x != u)
	{
		int tmp = color[x];
		color[x] = u;
		x = tmp;
	}
	return u;
}

void Union(int x, int y)
{
	int u = find(x);
	int v = find(y);
	if(u != v)
	{
		color[u] = v;
	}
	return;
}

int main()
{
	cin>>T;
	for(int t = 1; t <= T; ++t)
	{
		cin>>N>>K;
		for(int i = 1; i <= N; ++i)
		{
			cin>>A[i]>>B[i];
		}
		for(int i = 1; i <= N; ++i)
		{
			color[i] = i;
		}
		vector<int> pr;
		vector<int> po;
		pre(pr, 1);
		post(po, 1);
		for(int i = 0; i < N; ++i)
		{
			Union(pr[i], po[i]);
		}
		int connect = 0;
		vector<bool> pick(N+1, false);
		vector<int> labels(N+1, 0);
		int nxt = 0;
		for(int i = 1; i <= N; ++i)
		{
			if(!pick[find(i)])
			{
				++connect;
				pick[find(i)] = true;
				labels[find(i)] = ++nxt;
			}
		}
		if(connect < K)
		{
			cout<<"Case #"<<t<<": "<<"Impossible"<<endl;
			continue;
		}
		cout<<"Case #"<<t<<": ";
		for(int i = 1; i <= N; ++i)
		{
			if(labels[find(i)] > K)
			{
				cout<<1<<" ";
			}
			else
			{
				cout<<labels[find(i)]<<" ";
			}
		}
		cout<<endl;
		
	}
}
