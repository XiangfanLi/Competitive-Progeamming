#include <bits/stdc++.h>


using namespace std;

int t;
int n, m;

int a[110][2][2];
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i = 1; i <= n; ++i)
		{
			cin>>a[i][0][0]>>a[i][0][1];
			cin>>a[i][1][0]>>a[i][1][1];
		}
		if(m & 1)
		{
			cout<<"NO"<<endl;
		}
		else
		{
			bool ok = false;
			for(int i = 1; i <= n; ++i)
			{
				if(a[i][0][1] == a[i][1][0])
					ok = true;
			}
			if(ok)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
		
	}
	
	
}
