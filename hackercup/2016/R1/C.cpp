#include <bits/stdc++.h>


using namespace std;
#define ll long long
#define MAXN 100010
ll A, B;
int T;
int N;
ll C[MAXN];
ll pre[MAXN];
ll sum;

ll helper(ll from, ll to)
{
	ll ret = 0;
	
	ll s = A + (from - A % sum + sum) % sum;
	ll e = B - (B % sum - from + sum) % sum;
	
	ret += (e - s) / sum * (to - from) * (to - from);
	
	if(A % sum > from && A % sum < to)
	{
		ll low = A % sum - from;
		ret += (to - from) * (to - from) - low * low;
	}
	
	if(B % sum != from)
	{
		if(B % sum > from && B % sum < to)
		{
			ret += (B % sum - from) * (B % sum - from);
		}
		else
		{
			ret += (to - from) * (to - from);
		}
		
	}
	return ret;
}


int main()
{
	cin>>T;
	for(int t = 1; t <= T; ++t)
	{
		cin>>N>>A>>B;
		sum = 0;
		pre[0] = 0;
		for(int i = 1; i <= N; ++i)
		{
			cin>>C[i];
			sum += C[i];
			pre[i] = pre[i-1] + C[i];
		}
		ll ans = 0;
		for(int i = 1; i <= N; ++i)
		{
			ans += helper(pre[i-1], pre[i]);
		}
		cout<<"Case #"<<t<<": "<<fixed<<setprecision(7)<<(double)ans / (2*(B - A))<<endl;
	}
	
	
	
}
