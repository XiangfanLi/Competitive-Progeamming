#include <bits/stdc++.h>


using namespace std;
#define ll long long

ll N;
int X, M;

vector<ll> A;
map<ll, ll> idxs;
int main()
{
	cin>>N>>X>>M;
	A.push_back(0);
	A.push_back(X);
	idxs[X] = 1;
	ll last = X;
	ll ans = X;
	for(ll i = 2; i <= N; ++i)
	{
		last = last * last % M;
		if(idxs.count(last) != 0)
		{
			ll idx = idxs[last];
			ll len = i - idx;
			ll loop = (N - i + 1) / len;
			ll rest = (N - i + 1) - len * loop;
			ll tmp = 0;
			for(ll j = idx; j < i; ++j)
			{
				tmp += A[j];
			} 
			ans += loop * tmp;
			for(ll j = 0; j < rest; ++j)
				ans += A[idx+j];
			cout<<ans<<endl;
			return 0;
		}
		idxs[last] = i; 
		A.push_back(last);
		ans += last;
	}
	cout<<ans<<endl;
}
