#include <bits/stdc++.h>


using namespace std;
#define MAXN 100010
int X;
int A[MAXN];
int T;
int N;

int main()
{
	cin>>T;
	for(int t = 1; t <= T; ++t)
	{
		cin>>N;
		cin>>X;
		for(int i = 1; i <= N; ++i)
			cin>>A[i];
		vector<pair<int, int> > v;
		for(int i = 1; i <= N; ++i)
		{
			v.push_back(make_pair(ceil((double)A[i] / X), i));
		}
		sort(v.begin(), v.end());
		cout<<"Case #"<<t<<": ";
		for(auto& p: v)
			cout<<p.second<<" ";
		cout<<endl;
	}
	
}
