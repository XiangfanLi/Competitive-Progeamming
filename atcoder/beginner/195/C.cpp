#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll N;

int weishu(ll x)
{
	int ret = 0;
	while(x > 0)
	{
		x /= 10;
		++ret;
	}
	return ret;
}

ll comma(int ws)
{
	ll ret = 9;
	for(int i = 0; i < ws - 1; ++i)
		ret *= 10;
	ret *= (ws - 1) / 3;
	return ret;
}

int main()
{
	cin >> N;
	ll ans = 0;
	int ws = weishu(N);
	ll x = 1;
	for(int i = 1; i < ws; ++i)
	{
		ans += comma(i);
	}
	for(int i = 0; i < ws - 1; ++i)
	{
		x *= 10;
	}
	ans += (N - x + 1) * ((ws - 1) / 3);
	cout << ans << endl;
	return 0;
}
