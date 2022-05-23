#include <bits/stdc++.h>


using namespace std;

int T, N;
vector<int> nums[110];
int X[110];

void add1(vector<int>& num)
{
	reverse(num.begin(), num.end());
	int jw = 0;
	num[0]++;
	jw = num[0] / 10;
	num[0] %= 10;
	for(int i = 1; i < (int)num.size(); ++i)
	{
		num[i] += jw;
		jw = num[i] / 10;
		num[i] %= 10;
	}
	if(jw > 0)
		num.push_back(jw);
	reverse(num.begin(), num.end());
	return;
}

int main()
{
	cin >> T;
	for(int t = 1; t <= T; ++t)
	{
		cin >> N;
		for(int i = 1; i <= N; ++i)
		{
			cin >> X[i];
			nums[i].clear();
			int n = X[i];
			while(n > 0)
			{
				nums[i].push_back(n % 10);
				n /= 10;
			}
			reverse(nums[i].begin(), nums[i].end());
		}
		int ans = 0;
		for(int i = 2; i <= N; ++i)
		{
			if((int)nums[i].size() > (int)nums[i-1].size())
			{
				continue;
			} else if((int)nums[i].size() == (int)nums[i-1].size())
			{
				if (nums[i] > nums[i-1])
				{
					continue;
				} else
				{
					++ans;
					nums[i].push_back(0);
				}
			} else {
				int comp = 0;
				for(int j = 0; j < (int)nums[i].size(); ++j)
				{
					if(nums[i][j] != nums[i-1][j])
					{
						if(nums[i][j] < nums[i-1][j])
							comp = -1;
						else
							comp = 1;
						break;
					}
				}
				if(comp == 0)
				{
					bool all9 = true;
					for(int j = (int)nums[i].size(); j < (int)nums[i-1].size(); ++j)
					{
						if(nums[i-1][j] != 9)
						{
							all9 = false;
							break;
						}
					}
					if(all9)
					{
						int zeros = (int)nums[i-1].size() - (int)nums[i].size() + 1;
						for(int j = 0; j < zeros; ++j)
						{
							nums[i].push_back(0);
							++ans;
						}
					}
					else
					{
						ans += ((int)nums[i-1].size() - (int)nums[i].size());
						nums[i] = nums[i-1];
						add1(nums[i]);
					}
				} else if(comp > 0)
				{
					int zeros = (int)nums[i-1].size() - (int)nums[i].size();
					for(int j = 0; j < zeros; ++j)
						{
							nums[i].push_back(0);
							++ans;
						}
				} else
				{
					int zeros = (int)nums[i-1].size() - (int)nums[i].size() + 1;
					for(int j = 0; j < zeros; ++j)
						{
							nums[i].push_back(0);
							++ans;
						}
					
				}
			}
		}
		std::cout << "Case #" << t << ": " << ans << endl;
	}	
	
	
}
