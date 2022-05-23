#include <bits/stdc++.h>



using namespace std;

int t;
int n, x;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>x;
		if(n <= 2)
		{
			cout<<1<<endl;
		}
		else
		{
			int ans = ceil(double(n - 2) / x) + 1;
			cout<<ans<<endl;
		}
	}
}
