#include <bits/stdc++.h>



using namespace std;
int T, N, Q;
vector<int> sorted;

int Find(int l, int r, int num)
{
	cout << sorted[l] << " " << sorted[r] << " " << num << endl;
	int ret;
	cin >> ret;
	if (ret == sorted[l])
	{
		return -1;
	}
	if (ret == sorted[r])
		return -2;
	if (l + 1 == r)
	{
		return r;
	}
	int m = (l + r) >> 1;
	int ret1 = Find(l, m, num);
	if(ret1 >= 0)
		return ret1;
	return Find(m, r, num);
}


int main()
{
	int mid;
	cin >> T >> N >> Q;
	for(int t = 1; t <= T; ++t)
	{
		sorted.clear();
		if (Q <= 0) {
		    return 0;
		}
		--Q;
		cout << 1 << " " << 2 << " " << 3 << endl;
		cin >> mid;
		if(mid == 1)
		{
			sorted.push_back(2);
			sorted.push_back(1);
			sorted.push_back(3);
		} else if (mid == 2)
		{
			sorted.push_back(1);
			sorted.push_back(2);
			sorted.push_back(3);	
		} else {
			sorted.push_back(2);
			sorted.push_back(3);
			sorted.push_back(1);	
		}
		for(int i = 4; i <= N; ++i)
		{
			int low = 0;
			int high = (int)sorted.size() - 1;
			int ret = Find(low, high, i);
			if(ret == -1)
			{
				sorted.insert(sorted.begin(), i);
			} else if(ret == -2)
			{
				sorted.push_back(i);
			} else {
				sorted.insert(sorted.begin()+ret, i);
			}
		}
		for(auto i: sorted)
			cout << i << " ";
		cout << endl;
		cin >> mid;
	}
}
