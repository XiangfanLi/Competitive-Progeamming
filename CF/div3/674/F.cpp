#include <bits/stdc++.h>



using namespace std;
#define ll long long
#define MAXN 200010

const ll mod = (ll)(1e9+7);

ll dp[MAXN][4];
ll dp2[MAXN];
char s[MAXN];
int n;


int main()
{
	cin>>n;
	scanf("%s", s+1);
	memset(dp, 0, sizeof(dp));
	dp2[0] = 1;
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= 3; ++j)
		{
			dp[i][j] = dp[i-1][j];
		}
		dp2[i] = dp2[i-1];

		if(s[i] == 'a')
		{
			dp[i][1] = (dp[i-1][1] + dp2[i-1]) % mod;
		}
		else if(s[i] == 'b')
		{
			dp[i][2] = (dp[i-1][2] + dp[i-1][1]) % mod;
		}
		else if(s[i] == 'c')
		{
			dp[i][3] = (dp[i-1][3] + dp[i-1][2]) % mod;
		}
		else
		{
			
			dp[i][1] = (dp[i-1][1] * 3 + dp2[i-1]) % mod;
			dp[i][2] = (dp[i-1][2] * 3 + dp[i-1][1]) % mod;
			dp[i][3] = (dp[i-1][3] * 3 + dp[i-1][2]) % mod;
			dp2[i] = dp2[i-1] * 3 % mod;
		}
		//cout<<"dp["<<i<<"][1] = "<<dp[i][1]<<endl;
		//cout<<"dp["<<i<<"][2] = "<<dp[i][2]<<endl;
		//cout<<"dp["<<i<<"][3] = "<<dp[i][3]<<endl;
		
	}
	cout<<dp[n][3]<<endl;
}
