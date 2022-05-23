#include <bits/stdc++.h>


using namespace std;

int T;
int N;
int C, K;

int main()
{
	cin>>T;
	for(int t = 1; t <= T; ++t)
	{
		cin>>N>>K>>C;
		int ava = K / N;
		int rest = N - K + ava * N;
		int ans;
		if(C <= ava * N)
			ans = C;
		else
			ans = C + rest;
		cout<<"Case #"<<t<<": "<<ans<<endl;
	}
	
}
