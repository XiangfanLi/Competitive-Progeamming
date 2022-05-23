#include <bits/stdc++.h>


using namespace std;

#define MAXN 100010

int T;
int N;
int K;
int S[MAXN];
int E[MAXN];

int main()
{
	cin>>T;
	for(int t = 1; t <= T; ++t)
	{
		cin>>N>>K;
		vector<pair<int, int> > v;
		for(int i = 1; i <= N; ++i)
		{
			cin>>S[i]>>E[i];
			v.push_back(make_pair(S[i], E[i]));
		}
		sort(v.begin(), v.end());

		int ed = -1;
		int ans = 0;
		for(int i = 0; i < N; ++i)
		{
			int len = v[i].second - v[i].first;
			int st = v[i].first;
			if(ed != -1 && ed >= v[i].first)
			{
				len -= ed - v[i].first + 1;
				st = ed + 1;
			}
			//cout<<"len = "<<len<<endl;
			if(len > 0)
			{
				int ct = ceil((double)len / K);
				ans += ct;
				ed = st + ct * K - 1;
			}
		}
		cout<<"Case #"<<t<<": "<<ans<<endl;
	}
	
}
