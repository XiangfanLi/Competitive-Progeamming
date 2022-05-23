#include <bits/stdc++.h>


using namespace std;
#define ll long long
#define MAXN 200010
int L[20];
int R[20];
int K;
int N;

const ll mod = 998244353;

ll dp[MAXN];
ll sum[MAXN];

int main()
{
	cin>>N>>K;
	for(int i = 1; i <= K; ++i)
	{
		cin>>L[i]>>R[i];
	}
	memset(dp, 0, sizeof(dp));
	memset(sum, 0, sizeof(dp));
	dp[1] = 1;
	sum[1] = 1;
	for(int i = 2; i <= N; ++i)
	{
		for(int j = 1; j <= K; ++j)
		{
			int r = i - L[j];
			if(r < 1)
				continue;
			int l = max(1, i - R[j]);
			//cout<<"l = "<<l<<endl;
			//cout<<"r = "<<r<<endl;
			dp[i] += (sum[r] - sum[l-1]);
			dp[i] = (dp[i] % mod + mod) % mod;
			//cout<<"dp = "<<dp[i]<<endl;
		}
		sum[i] = (sum[i-1] + dp[i]) % mod;
	}
	cout<<dp[N]<<endl;
}
