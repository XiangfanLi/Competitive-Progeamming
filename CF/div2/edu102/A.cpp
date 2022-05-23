
#include <bits/stdc++.h>

using namespace std;

int t, n, d;

int a[110];

int main()
{
	cin >> t;
	for(int tt = 1; tt <= t; ++tt)
	{
		cin>>n>>d;
		bool ok = true;
		for(int i = 1; i <= n; ++i)
		{
			cin>>a[i];
			if(a[i] > d)
				ok = false;
		}
		if(ok)
		{
			cout << "YES" << endl;
			continue;
		}
		sort(a + 1, a + n + 1);
		if(a[1] + a[2] <= d)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
		return 0;
}
