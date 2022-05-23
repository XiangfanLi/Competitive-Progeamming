#include <bits/stdc++.h>



using namespace std;


int T;
int P;
string S;
bool correct[110][10010];
int rights[110];
int main()
{
	ios::sync_with_stdio(false);
	cin >> T;
	cin >> P;
	for(int t = 1; t <= T; ++t)
	{
		for(int i = 1; i <= 100; ++i)
		{
			cin >> S;
			for(int j = 0; j < 10000; ++j)
			{
				if(S[j] == '0')
				{
					correct[i][j+1] = false;
				}else
				{
					correct[i][j+1] = true;
				}
			}	
		}
		memset(rights, 0, sizeof(rights));
		vector<pair<int, int> > v;
		for(int j = 1; j <= 10000; ++j)
		{
			int cnt = 0;
			for(int i = 1; i <= 100; ++i)
			{
				if (correct[i][j])
				{
					++cnt;
					++rights[i];
				}
			}
			v.push_back(make_pair(cnt, j));
		}
		vector<int> hards;
		sort(v.begin(), v.end());
		for(int j = 0; j < 500; ++j)
		{
			// cout << "hardest " << j << "th = " << v[j].first << endl;
			hards.push_back(v[j].second);
		}
		int h_correct[110];
		memset(h_correct, 0, sizeof(h_correct));
		for(int i = 1; i <= 100; ++i)
		{
			for(int j: hards)
			{
				if(correct[i][j])
					++h_correct[i];
			}
		}
		
		
		vector<pair<int, int> > v2;
		for(int i = 1; i <= 100; ++i)
			v2.push_back(make_pair(rights[i], i));
		sort(v2.begin(), v2.end());
		double diffs[110];
		for(int i = 0; i < 100; ++i)
		{
			int nei = 0;
			double diff = 0;
			for(int j = i -1; j >= max(0, i - 5); --j)
			{
				++nei;
				diff += (double)(h_correct[v2[j].second]);
			}
			for(int j = i +1; j <= min(99, i+5); ++j)
			{
				++nei;
				diff += (double)(h_correct[v2[j].second]);
			}
			diff /= nei;
			diff = diff - h_correct[v2[i].second];
			diffs[v2[i].second] = diff;
		}
		
		for(int i = 1; i <= 100; ++i)
		{
			cout << "diffs[" << i << "] = " << diffs[i] << endl;
		}
		
		int ans_i = 1;
		for(int i = 2; i <= 100; ++i)
		{
			if(diffs[i] > diffs[ans_i])
				ans_i = i;
		}
		
		cout << "Case #" << t << ": " << ans_i << endl;
	}
	
}
