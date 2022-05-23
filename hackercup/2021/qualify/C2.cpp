#include <bits/stdc++.h>


using namespace std;

int T, N, K, A, B;
#define ll long long
ll C[60];
vector<int> neighs[60];
ll dp[60][60][2];
ll dp2[60][2]; // 2rd dimension: 0 means return to parent node.


void dfs3(int u, int p) {
	
	
	
	



void dfs(int u, int p, int tunnel) {
	//std::cout << "dfs(" << u << "," << p << "," << tunnel << ")" << std::endl;
	
	for(int v: neighs[u])
	{
		if(v != p)
			dfs(v, u, tunnel);
	}
	memset(dp2, 0, sizeof(dp2));
	for(int j = 0; j <= tunnel; ++j)
		dp2[j][0] = C[u];
	int i = 0;
	for(int v: neighs[u])
	{
		if(v == p)
			continue;
		++i;
		for(int j = 0; j <= tunnel; ++j) {
			if (j > 0) {
			dp2[j][0] = max(dp2[j][0], dp2[j-1][0]);
			dp2[j][0] = max(dp2[j][0], dp2[j-1][1]);	
			}
			for(int k = 0; k <= j; ++k) {
				if (j-k-1 >= 0) {
				dp2[j][0] = max(dp2[j][0],
							dp2[j-k-1][1] + dp[v][k][1]);
				//std::cout << "i = " << i << ", j = " << j << std::endl;
				//std::cout << "dp2[i][j][0] = " << dp2[i][j][0] << std::endl;
				//std::cout << "dp2[i-1][j-k-1][0] = " << dp2[i-1][j-k-1][0] << std::endl;
				//std::cout << "dp[v][k] = " << dp[v][k] << std::endl;
				dp2[j][0] = max(dp2[j][0],
							dp2[j-k-1][0] + dp[v][k][1]);	
				}
				dp2[j][1] = max(dp2[j][1],
							dp2[j-k][0] + dp[v][k][1]);
				if (j-k-1 >= 0)
				dp2[j][1] = max(dp2[j][1],
							dp2[j-k-1][1] + dp[v][k+1][1]);	
				
			}
			
		}
		for(int j = 0; j <= tunnel; ++j)
		{
			dp2[i][j][0] = dp2[i-1][j][0];
			dp2[i][j][1] = dp2[i-1][j][1];
			if(j > 0) {
				dp2[i][j][0] = std::max(dp2[i][j][0], dp2[i][j-1][0]);
				dp2[i][j][1] = std::max(dp2[i][j][1], dp2[i][j-1][1]);	
			}
			for(int k = 0; k <= j; ++k) {
				if (j-k-1 >= 0) {
				dp2[i][j][0] = max(dp2[i][j][0],
							dp2[i-1][j-k-1][1] + dp[v][k][1]);
				//std::cout << "i = " << i << ", j = " << j << std::endl;
				//std::cout << "dp2[i][j][0] = " << dp2[i][j][0] << std::endl;
				//std::cout << "dp2[i-1][j-k-1][0] = " << dp2[i-1][j-k-1][0] << std::endl;
				//std::cout << "dp[v][k] = " << dp[v][k] << std::endl;
				dp2[i][j][0] = max(dp2[i][j][0],
							dp2[i-1][j-k-1][0] + dp[v][k]);	
				}
				dp2[i][j][1] = max(dp2[i][j][1],
							dp2[i-1][j-k][0] + dp[v][k]);
				if (j-k-1 >= 0)
				dp2[i][j][1] = max(dp2[i][j][1],
							dp2[i-1][j-k-1][1] + dp[v][k+1]);	
				
			}
			/*std::cout << "dp2" << "[" << i << "][" << j << "][0] = " 
				<< dp2[i][j][0] << std::endl;
			std::cout << "dp2" << "[" << i << "][" << j << "][1] = " 
				<< dp2[i][j][1] << std::endl;*/
				
		}
	}
	for(int j = 0; j <= tunnel; ++j)
	{
		if(u == 1 && j == tunnel) {
			dp[u][j] = dp2[i][j][0];
		} else
		dp[u][j] = std::max(dp2[i][j][0], dp2[i][j][1]);	
	}
	return;
}

int main()
{
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		cin >> N >> K;
		for(int i = 1; i <= N; ++i)
		{
			cin >> C[i];
			neighs[i].clear();
			for(int j = 0; j <= K; ++j) {
				dp[i][j] = -1;
			}
		}
		for(int i = 1; i < N; ++i)
		{
			cin >> A >> B;
			neighs[A].push_back(B);
			neighs[B].push_back(A);
		}
		dfs(1, 0, K);
		std::cout << "Case #" << t << ": " << dp[1][K] << std::endl;
		
	}
}
