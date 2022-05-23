
#include <bits/stdc++.h>


using namespace std;
int N;
int T;
string L;

int main()
{
	cin>>T;
	for(int t = 1; t <= T; ++t)
	{
		cin>>L;
		N = L.size();
		int b = 0;
		for(int i = 1; i < N; ++i)
		{
			if(L[i] == 'B')
				++b;
		}	
		cout<<"Case #"<<t<<": ";
		if(b== N - 1 || b == 0)
		{
			cout<<"N"<<endl;
		}
		else if(b == 1)
		{
			if(N == 3)
				cout<<"Y"<<endl;
			else
				cout<<"N"<<endl;
		}
		else
		{
			cout<<"Y"<<endl;
		}
	}
	
}
