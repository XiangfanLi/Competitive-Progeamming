#include <bits/stdc++.h>


using namespace std;
#define MAXN 100010

int T;
int D[MAXN];
int cnt[101];
int N;




int main()
{
	cin>>T;
	for(int t = 1; t <= T; ++t)
	{
		cin>>N;
		for(int i = 1; i <= 100; ++i)
		{
			cnt[i] = 0;
		}
		for(int i = 1; i <= N; ++i)
		{
			cin>>D[i];
			cnt[D[i]]++;
		}
		int ans = 0;
		int i = 1;
		while(i <= 100)
		{
			if(cnt[i] == 0)
			{	
				++i;
				continue;
			}
			int loop = 3;
			int start = i;
			cnt[i]--;
			while(loop--)
			{
				bool found = false;
				for(int j = start + 1; j <= min(start + 10, 100); ++j)
				{
					if(cnt[j] > 0)
					{
						--cnt[j];
						start = j;
						found = true;
						break;
					}
				}
				if(!found)
				{
					++loop;
					break;
				}
			}
			if(loop == -1)
				++ans;
			ans += loop;
		}
		cout<<"Case #"<<t<<": "<<ans<<endl;
	}
	
}
