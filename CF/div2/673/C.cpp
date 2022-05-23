#include<bits/stdc++.h>


using namespace std;
#define MAXN 300010

int t;
int n;
int a[MAXN];
bool appear[MAXN];
int win[MAXN];
int last[MAXN];

int main()
{
	cin.sync_with_stdio(false);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i = 1; i <= n; ++i)
		{
			appear[i] = false;
		}
		for(int i = 1; i <= n; ++i)
		{
			cin>>a[i];
			appear[a[i]] = true;
		}
		for(int i = 1; i <= n; ++i)
		{
			win[i] = 0;
			last[i] = 0;
		}
		for(int i = 1; i <= n; ++i)
		{
			win[a[i]] = max(win[a[i]], i - last[a[i]] - 1);
			last[a[i]] = i;
		}
		for(int i = 1; i <= n; ++i)
		{
			if(appear[i])
				win[i] = max(win[i], n - last[i]);
		}
		vector<pair<int, int> > v;
		for(int i = 1; i <= n; ++i)
		{
			if(appear[i])
				v.push_back(make_pair(win[i], -i));
		}
		sort(v.begin(), v.end());
		vector<int> ans;
		int nxt = 0;
		int Min = n + 1;
		for(int k = 1; k <= n; ++k)
		{
			if(v[0].first >= k)
			{
				ans.push_back(-1);
				continue;
			}
			while(nxt < (int)v.size() && v[nxt].first < k)
			{
				Min = min(Min, -v[nxt].second);
				++nxt;
			}
			ans.push_back(Min);
		}
		
		for(int i: ans)
			cout<<i<<" ";
		cout<<endl;
	}


	
}
