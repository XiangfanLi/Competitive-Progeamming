#include <bits/stdc++.h>


using namespace std;
int T, N;
char state[60][60];
int row[2][60];
int col[2][60];

#define INF 99999
int main() {
	
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		memset(state, 0, sizeof(state));
		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));
		cin >> N;
		for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			cin >> state[i][j];
		for(int i = 0; i < N; ++i)
		{
			for(int j = 0; j < N; ++j) {
				if(state[i][j] == 'X')
				{
					row[0][i]++;
					col[0][j]++;
				} else if (state[i][j] == 'O') {
					row[1][i]++;
					col[1][j]++;
				}
			}
		}
		int ans1 = INF;
		int ans2 = 0;
		for(int i = 0; i < N; ++i)
		{
			if(row[1][i] == 0) {
				int need = N - row[0][i];
				if(need < ans1)
				{
					ans1 = need;
					ans2 = 1;
				} else if(need == ans1)
				{
					ans2++;
				}
			}
		}
		
		for(int j = 0; j < N; ++j)
		{
			if(col[1][j] == 0) {
				int need = N - col[0][j];
				if(need < ans1)
				{
					ans1 = need;
					ans2 = 1;
				} else if(need == ans1)
				{
					ans2++;
				}
			}
		}
		std::cout << "Case #" << t << ": ";
		if (ans1 == INF) {
			std::cout << "Impossible" << std::endl;
		}
		else {
			for(int i = 0; i < N; ++i) {
				for(int j = 0; j < N; ++j) {
					if(ans1 == 1 && row[1][i] == 0 &&
						col[1][j] == 0 &&
						row[0][i] == N - 1 &&
						col[0][j] == N - 1 &&
						state[i][j] == '.') {
							ans2--;
					}
				}
			}
			std::cout << ans1 << " " << ans2 << std::endl;
		}

		
	}
}
