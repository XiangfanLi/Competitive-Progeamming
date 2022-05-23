#include <bits/stdc++.h>


using namespace std;
int N;
int main()
{
	cin>>N;
	int sqt = sqrt(N);
	int ans = 0;
	for(int A = 1; A <= N; ++A)
	{
		int B = N / A;
		if(A * B == N)
			ans += (B - 1);
		else
			ans += B;
	}
	cout<<ans<<endl;
	
}
