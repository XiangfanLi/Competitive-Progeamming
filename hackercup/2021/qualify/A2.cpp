#include <bits/stdc++.h>


using namespace std;
#define INF 9999999

int T;
int K;
char A, B;
string S;
int dist[26][26];
int N;


int main()
{
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		for(int i = 0; i < 26; ++i)
		for(int j = 0; j < 26; ++j)
			dist[i][j] = (i == j) ? 0 : INF;
		cin >> S;
		N = (int)S.size();
		cin >> K;
		for (int k = 1; k <= K; ++k) {
			cin >> A >> B;
			dist[A - 'A'][B - 'A'] = 1;
		}
		
		while(true) {
			bool change = false;
			for(int i = 0; i < 26; ++i)
			for(int j = 0; j < 26; ++j) {
				if (i == j)
					continue;
				for(int k = 0; k < 26; ++k) {
					if (dist[i][k] + dist[k][j] < dist[i][j]) {
						dist[i][j] = dist[i][k] + dist[k][j];
						change = true;
					}
				}
			}
			if (!change)
			break;
		}
		int ans = INF;
		for(int res = 0; res < 26; ++res) {
			int curr_ans = 0;
			bool ok = true;
			for(int i = 0; i < N; ++i)
			{
				if(dist[S[i]-'A'][res] >= INF) {
					ok = false;
					break;
				}
				curr_ans += dist[S[i]-'A'][res];
			}
			if (ok)
				ans = min(ans, curr_ans);
		}
		std::cout << "Case #" << t << ": " << ((ans >= INF) ? -1 : ans) << std::endl;
	}
	
}

