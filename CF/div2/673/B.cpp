#include<bits/stdc++.h>


using namespace std;
#define MAXN 100010

int T;
int n;
int a[MAXN];
int color[MAXN];

int t;

map<int, vector<int> > Map;
map<int, bool> vis;

int main()
{
	cin.sync_with_stdio(false);
	cin>>t;
	while(t--)
	{
		cin>>n>>T;
		Map = map<int, vector<int> >();
		vis = map<int, bool> ();
		for(int i = 1; i <= n; ++i)
		{
			cin>>a[i];
			Map[a[i]].push_back(i);
		}
		int ans = 0;
		for(int i = 1; i <= n; ++i)
		{
			if(vis.count(a[i]) != 0)
				continue;
			int ano = T - a[i];
			if(Map.count(ano) == 0)
			{
				continue;
			}
			if(a[i] == ano)
			{
				auto& v = Map[ano];
				int cnt = (int)v.size();
				int hf = cnt / 2;
				for(int i = 0; i < hf; ++i)
				{
					color[v[i]] = 0;
				}
				for(int i = hf; i < cnt; ++i)
				{
					color[v[i]] = 1;
				}
				ans += hf * (hf - 1) / 2;
				ans += (cnt - hf) * (cnt - hf - 1) / 2;
			}
			else
			{
				auto& v = Map[a[i]];
				auto& v2 = Map[ano];
				for(int i: v)
				{
					color[i] = 0;
				}
				for(int i: v2)
				{
					color[i] = 1;
				}
			}
			vis[a[i]] = true;
			vis[ano] = true;
		}
		for(int i = 1; i <= n; ++i)
		{
			cout<<color[i]<<" ";
		}
		cout<<endl;
		
		
	}


	
}
