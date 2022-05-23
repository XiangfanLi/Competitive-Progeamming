#include <bits/stdc++.h>


using namespace std;

#define MAXN 200010
int T, N;

vector<int> sons[MAXN];

int cnt[2];

void dfs(int u, int color)
{
	cnt[color]++;
	for(int v: sons[u])
	{
		dfs(v, 1 - color);
	}
	return;
}


int main()
{
	cin>>T;
	for(int t = 1; t <= T; ++t)
	{
		cin>>N;
		for(int i = 0; i <= N; ++i)
			sons[i].clear();
		for(int i = 1; i <= N; ++i)
		{
			int f;
			cin>>f;
			sons[f].push_back(i);	
		}
		cnt[0] = cnt[1] = 0;
		dfs(1, 0);
		int ans = min(cnt[0], cnt[1]) * 2 + max(cnt[0], cnt[1]) * 1;
		cout<<"Case #"<<t<<": "<<ans<<endl;
	}
	
	
}
