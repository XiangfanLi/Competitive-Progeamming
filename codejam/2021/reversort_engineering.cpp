#include <bits/stdc++.h>


using namespace std;

int T;
int N;
int C;
int L[110];

int main()
{
	cin >> T;
	for(int t = 1; t <= T; ++t)
	{
		cin >> N >> C;
		int max_C = (N + 2) * (N - 1) / 2;
		int min_C = N - 1;
		if(C < min_C || C > max_C)
		{
			cout << "Case #" << t << ": IMPOSSIBLE" << endl;
			continue;
		}
		vector<int> js;
		for(int i = 1; i < N; ++i)
		{
			int remain_c_max = (N - i + 2) * (N - i - 1) / 2;
			int curr_min = C - remain_c_max;
			int curr = max(1, curr_min);
			L[i + curr - 1] = i;
			reverse(L+i, L + i +curr);
			js.push_back(i + curr);
			C -= curr;
		}
		L[N] = N;
		int i = N - 1;
		while(!js.empty())
		{
			int j = js.back();
			reverse(L+i,L+j);
			js.pop_back();
			i--;
		}
		cout << "Case #" << t << ": ";
		for(int j = 1; j <= N; ++j)
		{
			std::cout << L[j] << " ";	
		}
		std::cout << endl;
	}
	
	
}
