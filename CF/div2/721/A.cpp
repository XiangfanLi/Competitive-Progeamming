#include <bits/stdc++.h>


using namespace std;

int n;
int t;

int main()
{
	cin >> t;
	while(t--)
	{
		cin >> n;
		int ans = n - 1;
		int high;
		for(int i = 0; i <= 30; ++i)
		{
			if(n & (1 << i))
				high = i;
		}
		
			ans = (1 << high) - 1;
		cout << ans << endl;
		
	}
	
	
}
