#include<bits/stdc++.h>


using namespace std;
#define MAXN 1010

int T, n, k;
int a[MAXN];
int main()
{
	cin>>T;
	for(int t = 1; t <= T; ++t)
	{
		cin>>n>>k;
		for(int i = 1; i <= n; ++i)
			cin>>a[i];
		
		sort(a+1, a+n+1);
		int ans = 0;
		for(int i = 2; i <= n; ++i)
		{
			ans += (k - a[i])/ a[1];
		}
		cout<<ans<<endl;
	}
	
}
