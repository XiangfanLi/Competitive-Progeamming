#include <bits/stdc++.h>


using namespace std;

int t;
int n;

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a = sqrt(n);
		
		cout<<(a + ceil((double)n / a) - 2)<<endl;
	}
	
	
	
}
