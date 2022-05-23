
#include <bits/stdc++.h>

using namespace std;
#define ll long long

const ll mod = (ll)(1e9+7);

#define MAXN 1000010
int T;
int N, K, W;

ll AL, BL, CL, DL;

ll AH, BH, CH, DH;
ll L[MAXN];
ll H[MAXN];

int main()
{
	ios::sync_with_stdio(false);
	cin>>T;
	cout<<"T = "<<T<<endl;
	for(int tt = 1; tt <= T; ++tt)
	{
		cin>>N>>K>>W;
		cout<<"N = "<<N<<endl;
		for(int i = 1; i <= K; ++i)
		{
			cin>>L[i];
		}
		cin>>AL>>BL>>CL>>DL;
		for(int i = 1; i <= K; ++i)
		{
			cin>>H[i];
		}
		cin>>AH>>BH>>CH>>DH;
		for(int i = K + 1; i <= N; ++i)
		{
			L[i] = ((AL*L[i-2]+BL*L[i-1]+CL) % DL) + 1;
			H[i] = ((AH*H[i-2]+BH*H[i-1]+CH) % DH) + 1;
		}
		priority_queue<pair<ll, ll> > q;
		q.push(make_pair(H[1], L[1] + W));
		ll ans = 2 * (W + H[1]);
		ll last = 2 * (W + H[1]);
		for(int i = 2; i <= N; ++i)
		{
			cout<<"i = "<<i<<endl;
			while(!q.empty() && q.top().second < L[i])
				q.pop();
			if(q.empty())
			{
				last = last + 2 * (W + H[i]);
				last %= mod;
				ans = ans * last % mod;
			}
			else
			{
				ll t = q.top().first;
				if(t >= H[i])
				{
					last = last + 2 * (L[i] - L[i-1]);
					last %= mod;
					ans = ans * last % mod;
				}
				else
				{
					last = last + 2 * (H[i] - t) + 2 * (L[i] - L[i-1]);
					last %= mod;
					ans = ans * last % mod;
				}
			}
			q.push(make_pair(H[i], L[i] + W));		
		}
		cout<<"Case #"<<tt<<": "<<ans<<endl;
	}
	
}
