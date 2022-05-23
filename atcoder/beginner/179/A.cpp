#include <bits/stdc++.h>


using namespace std;
string S;

int main()
{
		cin>>S;
		if(S.back() == 's')
		{
			S += "es";
		}
		else
		{
			S += "s";
		}
		cout<<S<<endl;
		return 0;
}
