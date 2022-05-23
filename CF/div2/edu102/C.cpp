
#include <bits/stdc++.h>

using namespace std;

#define MAXN 100010

int n, k;

int t;
//int a[MAXN];

int main()
{
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		for(int i = 1; i <= 2 * k - n - 1; ++i)
			cout << i << " ";
		for(int i = 2 * k - n; i <= k; ++i)
		{
			cout << k - i + 2 * k - n << " ";
		}
		cout << endl;
		
	}
	
		return 0;
}
