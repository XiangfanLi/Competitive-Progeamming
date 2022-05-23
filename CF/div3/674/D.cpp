#include <bits/stdc++.h>



using namespace std;
#define MAXN 200010
#define ll long long

int n;
ll a[MAXN];
map<ll, int> Map;

int main()
{
	cin>>n;
	for(int i = 1; i <= n; ++i)
	{
		cin>>a[i];
	}
	int ans = 0;
	ll sum = 0;
	Map[0] = 0;
	int last = 0;
	for(int i = 1; i <= n; ++i)
	{
		sum += a[i];
		if(Map.count(sum) != 0)
		{
			int r = Map[sum];
			if(last > r + 1)
			{
				
			}
			else
			{
				++ans;
				last = i;
			}
		}
		Map[sum] = i;
	}
	cout<<ans<<endl;
}
