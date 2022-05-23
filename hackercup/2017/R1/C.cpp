
#include <bits/stdc++.h>

#define MAXN 2010
#define ll long long
const ll mod = (ll)(1e9+7);
using namespace std;


ll M;
ll N;
ll R[MAXN];
ll fac[MAXN];
ll A[5000];
int T;


ll qpow(ll x, ll k)
{	
	ll ans = 1;
	while(k)
	{
		if(k & 1)
			ans = ans * x % mod;
		k >>= 1;
		x = x * x % mod;
	}
	return ans;
}

ll inv(ll x)
{
		return qpow(x, mod - 2);
}



int main()
{
	fac[0] = 1;
	for(int i = 1; i <= 2002; ++i)
	{
		fac[i] = fac[i-1] * i % mod;
	}
	cin>>T;
	for(int t = 1; t <= T; ++t)
	{
		cin>>N>>M;
		ll dsum = 0;
		for(int i = 1; i <= N; ++i)
		{
			cin>>R[i];
			dsum += 2 * R[i];
		}
		cout<<"Case #"<<t<<": ";
		sort(R+1, R+N+1);
		if(N > 1 && dsum - R[N] - R[N-1] > M - 1)
		{
			cout<<0<<endl;
			continue;
		}
		if(N == 1)
		{
			cout<<M<<endl;
			continue;
		}
		ll Max = M - 1 - (dsum - R[N-1] - R[N]) + (N + 1) - 1;
		ll Min = M - 1 - (dsum - R[1] - R[2]) + (N + 1) - 1;
		// A(Max, N) ~ A(Min, N)
		A[0] = 1;
		for(ll i = Max; i >= Max - N + 1; --i)
		{
			A[0] = A[0] * i % mod;
		}
		for(ll m = Max; m > Min; --m)
		{
			A[Max-m+1] = A[Max-m] * inv(m) % mod * (m -N) % mod;
		}
		
		ll ans = 0;
		for(int i = 1; i <= N; ++i)
		{
			for(int j = 1; j <= N; ++j)
			{
				if(i == j)
					continue;
				ll re = M - 1 - (dsum - R[i] - R[j]);
				if(re < 0)
					continue;
				ll m = re + N + 1 - 1;
				
				ans += A[Max-m] * inv(fac[N]) % mod * fac[N-2] % mod;
				ans %= mod;
			}
		}
		cout<<ans<<endl;
		
	}
	
}
