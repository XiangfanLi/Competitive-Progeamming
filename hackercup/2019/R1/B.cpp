#include <bits/stdc++.h>


using namespace std;

#define ll long long
#define MAXN 1000010

const ll mod = (ll)(1e9+7);
ll fac2[MAXN];
char V[MAXN];
int suf[MAXN];
//int suf_min[MAXN];



int K;
int N;
int T;


int main()
{
	fac2[0] = 1;
	for(int i = 1; i <= 1000000; ++i)
	{
		fac2[i] = fac2[i-1] * 2 % mod;
	}
	cin>>T;
	for(int t = 1; t <= T; ++t)
	{
		cin>>N>>K;
		scanf("%s", V+1);
		int suf_min = 0;
		ll ans = 0;
		for(int i = N; i >= 1; --i)
		{
			if(V[i] == 'B')
			{
				if(suf_min - 1 < -K)
				{
					V[i] = 'A';
					ans = (ans + fac2[i]) % mod;
				}	
			}
			suf_min = min(0, suf_min + ((V[i] == 'A') ? 1 : -1));
		}
		cout<<"Case #"<<t<<": "<<ans<<endl;
		
	}	
}
