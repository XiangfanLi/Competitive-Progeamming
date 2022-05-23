
#include <bits/stdc++.h>

using namespace std;
#define MAXN 3010

int n;
int a[MAXN];
int b[MAXN];

int c[110];

int main()
{
	memset(c, 0, sizeof(c));
	cin >> n;
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= n; ++i)
	{
		cin >> b[i];
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i)
	{
		int sum = b[i];
		for(int aj = 1; aj <= a[i]; ++aj)
		{
			if(a[i] % aj == 0)
				sum += c[aj];
		}
		ans = max(ans, sum);
		c[a[i]] += b[i];
	}
	cout << ans << endl;
}
