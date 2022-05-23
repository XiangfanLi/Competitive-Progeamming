#include <bits/stdc++.h>


using namespace std;

#define MAXN 110
int T, N;

int L[MAXN];

int main()
{
	cin >> T;
	for(int t = 1; t <= T; ++t)
	{
		cin >> N;
		for(int i = 1; i <= N; ++i)
		{
			cin >> L[i];
		}
		int cost = 0;
		for(int i = 1; i < N; ++i)
		{
			int min_j = i;
			for(int j = i; j <= N; ++j)
			{
				if(L[j] < L[min_j])
					min_j = j;
			}
			cost += (min_j - i + 1);
			reverse(L+i, L+min_j+1);
		}
		cout << "Case #" << t << ": " <<cost<<std::endl;
	}
	
	
}
