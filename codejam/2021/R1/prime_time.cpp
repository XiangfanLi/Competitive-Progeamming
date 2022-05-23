#include <bits/stdc++.h>


using namespace std;
#define ll long long

int T, M;
ll P[110];
ll N[110];
//vector<ll> primes;

ll is_can(ll n)
{
	ll ret = 0;
	for(int i = 1; i <= M; ++i)
	{
		ll cnt = 0;
		while(n % P[i] == 0)
		{
			++cnt;
			n /= P[i];
			ret += P[i];
			if(cnt > N[i])
				return -1;
		}
	}
	if(n == 1)
		return ret;
	return -1;
}
int main()
{
	cin >> T;
	for(int t = 1; t <= T; ++t)
	{
	//	primes.clear();
		cin >> M;
		ll totalN = 0;
		ll total = 0;
		for(int i = 1; i <= M; ++i)
		{
			cin >> P[i] >> N[i];
		//	primes.push_back(P[i]);
			totalN += N[i];
			total += N[i] * P[i];
		}
		ll ans = 0;
		for(ll x = 1; x <= total; ++x)
		{
			ll half = is_can(x);
			if(half < 0)
				continue;
			if(total - half == x)
				ans = max(x, ans);
		}
		cout << "Case #" << t << ": " << ans << endl;
	}
	
	
}
