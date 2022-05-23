#include <bits/stdc++.h>


using namespace std;

string s;

int t;
int n;
int main()
{
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--){
		cin >> n;
		cin >> s;
		int cnt00 = 0;
		int cnt01 = 0;
		int cnt0 = 0;
		int half = n / 2;
		int pay[2];
		pay[0] = pay[1] = 0;
		for(int i = 0; i < half; ++i)
		{
			int p = (s[i]-'0') + (s[n-1-i]-'0');
			if (p == 0)
				cnt00++;
			else if(p == 1)
				cnt01++;
			
		}
		if(n % 2 == 1 && s[half] == '0')
			cnt0++;
		int turn = 0;
		bool lastreverse = false;
		while(true){
			if(cnt0 + cnt01+ cnt00 == 0)
				break;
			if(cnt01 == 0)
			{
				// huiwen
				if(cnt0 > 0)
					--cnt0;
				else
				{
					--cnt00;
					++cnt01;
				}
				lastreverse = false;
				pay[turn]++;
			} else
			{
				if (lastreverse)
				{
					--cnt01;
					pay[turn]++;
					lastreverse = false;
				} else
				{
					lastreverse = true;
				}
			}
			
			turn = 1 - turn;
		}
		if(pay[0] < pay[1])
			cout << "ALICE" << endl;
		else if(pay[1] < pay[0])
			cout << "BOB" << endl;
		else
			cout << "DRAW" << endl;
		
	}
	
	
}
