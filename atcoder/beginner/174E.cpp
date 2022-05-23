#include <bits/stdc++.h>


using namespace std;
int K;
#define MAXN 200010
int N;
int A[MAXN];


bool can(int target)
{
	int cnt = 0;
	for(int i = 1; i <= N; ++i)
	{
		cnt += ceil((double)A[i] / target) - 1;
	}
	return (cnt <= K);
}

int main()
{
	cin>>N>>K;
	int Max = 0;
	for(int i = 1; i <= N; ++i)
	{
		cin>>A[i];
		Max = max(Max, A[i]);
	}
	int begin = 1;
	int end = Max;
	while(begin < end)
	{
		int mid = (begin + end) /2;
		if(can(mid))
		{
			end = mid;
		}
		else
		{
			begin = mid + 1;
		}
	}
	cout<<begin<<endl;
}
