#include <bits/stdc++.h>


using namespace std;

int n;
int a[4];
int b[4];
int main()
{
	cin>>n;
	for(int i = 1; i <= 3; ++i)
	{
		cin>>a[i];
	}
	for(int i = 1; i <= 3; ++i)
	{
		cin>>b[i];
	}
	int ans1 = min(a[1], b[2]) + min(a[2], b[3]) + min(a[3], b[1]);
	
	int ans2 = 0;
	if(a[1] + a[2] < b[1])
		ans2 += (b[1] - a[1] - a[2]);
	if(a[2] + a[3] < b[2])
		ans2 += (b[2] - a[2] - a[3]);
	if(a[1] + a[3] < b[3])
		ans2 += (b[3] - a[1] - a[3]);
		
	cout<<ans2<<" "<<ans1<<endl;
	
}
