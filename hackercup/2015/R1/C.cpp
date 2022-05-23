#include <bits/stdc++.h>


using namespace std;

int T;
#define MAXN 2010

const int mod = (int)(1e9+7);
int dp1[MAXN][MAXN];
int dp2[MAXN][MAXN];
int A, B;
int main()
{
	cin>>T;
	for(int t  = 1; t <= T; ++t)
	{
		memset(dp1, 0,sizeof(dp1));
		memset(dp2, 0,sizeof(dp2));
		scanf("%d-%d", &A, &B);
		for(int i = 0; i <= A; ++i)
			dp1[i][0] = 1;
		for(int i = 1; i <= A; ++i)
		for(int j = 1; j <= min(B, i -1); ++j)
		{
			if(i - j > 1)
				dp1[i][j] = (dp1[i][j] + dp1[i-1][j]) % mod;
			dp1[i][j] = (dp1[i][j] + dp1[i][j-1]) % mod;
		}
		
		dp2[0][0] = 1;
		for(int j = 1; j < B; ++j)
		{
			dp2[0][j] = 1;
			for(int i = 1; i <= min(j, A); ++i)
			{
				if(i < j)
					dp2[i][j] = (dp2[i][j] + dp2[i][j-1]) % mod;
				dp2[i][j] = (dp2[i][j] + dp2[i-1][j]) % mod;	
			}	
		}
		dp2[0][B] = 1;
		for(int i = 1; i <= A; ++i)
		{
			dp2[i][B] = (dp2[i][B] + dp2[i-1][B]) % mod;
			if(i <= B - 1)
				dp2[i][B] = (dp2[i][B] + dp2[i][B-1]) % mod;
		}
		
		cout<<"Case #"<<t<<": "<<dp1[A][B]<<" "<<dp2[A][B]<<endl;
		
	}
	
}
