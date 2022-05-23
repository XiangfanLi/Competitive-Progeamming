#include <bits/stdc++.h>


using namespace std;


int D[102][2];
int N;

int main()
{
	cin>>N;
	for(int i = 1; i <= N; ++i)
	{
		cin>>D[i][0]>>D[i][1];
	}
	for(int i = 1; i <= N - 2; ++i)
	{
		if(D[i][0] == D[i][1] 
			&& D[i+1][0] == D[i+1][1]
			&& D[i+2][0] == D[i+2][1])
		{
			cout<<"Yes"<<endl;
			return 0;
		}
	}
	cout<<"No"<<endl;
}
