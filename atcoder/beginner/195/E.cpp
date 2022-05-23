#include <bits/stdc++.h>

using namespace std;

int N;
string S, X;

bool dp[200010][7]; // Whether T Wins.
int mod7[200010];
int main()
{
	cin >> N;
	cin >> S;
	cin >> X;
	dp[N][0] = true;
	for(int i = 1; i < 7; ++i)
		dp[N][i] = false;
	int xx = 1;
	for(int i = N - 1; i >= 0; --i)
	{
		mod7[i] = xx;
		xx = xx * 10 % 7;
	}
	for(int i = N-1; i >= 0; --i)
	{
		int x = S[i] - '0';
		
		for(int j = 0; j < 7; ++j)
		{
			if(X[i] == 'T')
			{
				if(dp[i+1][(j+x*mod7[i])%7] || dp[i+1][j%7])
				{
					dp[i][j] = true;
				}
				else
				{
					dp[i][j] = false;
				}
			} else {
				if(dp[i+1][(j+x*mod7[i])%7] == false || dp[i+1][j%7] == false)
				{
					dp[i][j] = false;
				}
				else
				{
					dp[i][j] = true;
				}
			}
		}
	}
	if(dp[0][0])
		cout << "Takahashi" << endl;
	else
		cout << "Aoki" << endl;
	
	
}
