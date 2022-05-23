#include <bits/stdc++.h>


using namespace std;
#define MAXN 1010

int T;
string S;
int dp[MAXN][2]; // 0 means C, 1 means J
int X, Y;

int main()
{
	cin >> T;
	for(int t = 1; t <= T; ++t)
	{
		cin >> X >> Y;
		cin >> S;
		int n = (int)S.size();
		dp[0][0] = 0;
		dp[0][1] = 0;
		
		for(int i = 1; i < n; ++i)
		{
			if(S[i] == 'C')
			{
				if(S[i-1] == 'C')
				{
					dp[i][0] = dp[i-1][0];
				}
				else if (S[i-1] == 'J')
					dp[i][0] = dp[i-1][1] + Y;
				else
					dp[i][0] = min(dp[i-1][0], dp[i-1][1] + Y);
			} else if (S[i] == 'J')
			{
				if(S[i-1] == 'C')
				{
					dp[i][1] = dp[i-1][0] + X;
				}
				else if (S[i-1] == 'J')
					dp[i][1] = dp[i-1][1];
				else
					dp[i][1] = min(dp[i-1][1], dp[i-1][0] + X);
				
			} else {
				if(S[i-1] == 'C')
				{
					dp[i][0] = dp[i-1][0];
					dp[i][1] = dp[i-1][0] + X;
				}
				else if (S[i-1] == 'J')
				{
					dp[i][1] = dp[i-1][1];
					dp[i][0] = dp[i-1][1] + Y;
				}
				else
				{
					dp[i][1] = min(dp[i-1][1], dp[i-1][0] + X);	
					dp[i][0] = min(dp[i-1][0], dp[i-1][1] + Y);
				}
			}
		}
		int ans;
		if (S[n-1] == 'C')
			ans = dp[n-1][0];
		else if (S[n-1] == 'J')
			ans = dp[n-1][1];
		else
			ans = min(dp[n-1][1], dp[n-1][0]);
		
		
		std::cout << "Case #" << t << ": " << ans << endl;
	}
	
	
}
