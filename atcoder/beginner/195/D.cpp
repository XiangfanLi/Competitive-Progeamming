#include <bits/stdc++.h>


using namespace std;

int N, M, Q;

int W[60];
int V[60];
int X[60];

int L, R;

int main()
{
	cin >> N >> M >> Q;
	for(int i = 1; i <= N; ++i)
	{
		cin >> W[i] >> V[i];
	}
	for(int i = 1; i <= M; ++i)
		cin >> X[i];
		
		
	for(int i = 1; i <= Q; ++i)
	{
		cin >> L >> R;
		vector<int> boxes;
		for(int j = 1; j < L; ++j)
		{
			boxes.push_back(X[j]);
		}
		for(int j = R + 1; j <= M; ++j)
			boxes.push_back(X[j]);
		sort(boxes.begin(), boxes.end());
		vector<bool> choose(N + 1, false);
		int ans = 0;
		for(int cap : boxes)
		{
			int best_v = 0;
			int best_j = 0;
			for(int j = 1; j <= N; ++j)
			{
				if(!choose[j] && W[j] <= cap && V[j] > best_v)
				{
					best_j = j;
					best_v = V[j];
				} 
			}
			if(best_j != 0)
			{
				choose[best_j] = true;
				ans += best_v;
			}
		}
		cout << ans << endl;
	} 
	
}
