#include <bits/stdc++.h>


using namespace std;

int A, B, K, T;

int pri[10000002];

int main()
{
	for(int i = 2; i <= 10000000; ++i)
		pri[i] = 0;
	int sqt = sqrt(10000000);
	for(int i = 2; i <= 10000000; ++i)
	{
		if(pri[i] == 0)
		{
			for(int j = 1; i * j <= 10000000; ++j)
			{
				pri[i*j]++;
			}
		}
	}
	
	cin>>T;
	for(int t = 1; t <= T; ++t)
	{
		cin>>A>>B>>K;
		int ans = 0;
		for(int i = A; i <= B; ++i)
		{
			if(pri[i] == K)
				++ans;
		}
		cout<<"Case #"<<t<<": "<<ans<<endl;
	}
	
}
