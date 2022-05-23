
#include <bits/stdc++.h>

using namespace std;

#define MAXN 200010

int t;
int n, m;
int l, r;
char inst[MAXN];
int l_max[MAXN];
int l_min[MAXN];
int r_max[MAXN];
int r_min[MAXN];
int h[MAXN];
int h2[MAXN];

int main()
{
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		for(int i = 1; i <= n; ++i)
			cin >> inst[i];
		l_max[0] = l_min[0] = 0;
		int curr = 0;
		h[0] = 0;
		for(int i = 1; i <= n; ++i)
		{
			if(inst[i] == '+')
			{
				curr++;
				l_max[i] = max(l_max[i-1], curr);
				l_min[i] = min(l_min[i-1], curr);
			}
			else
			{
				curr--;
				l_max[i] = max(l_max[i-1], curr);
				l_min[i] = min(l_min[i-1], curr);		
			}
			h[i] = curr;
		}
		r_max[n] = r_min[n] = 0;
		curr = 0;
		h2[n] = 0;
		for(int i = n; i >= 1; --i)
		{
			if(inst[i] == '+')
			{
				curr--;
				r_max[i-1] = max(r_max[i], curr);
				r_min[i-1] = min(r_min[i], curr);
			}
			else
			{
				curr++;
				r_max[i-1] = max(r_max[i], curr);
				r_min[i-1] = min(r_min[i], curr);		
			}
			h2[i-1] = curr;
		}
		while(m--)
		{
			cin >> l >> r;
			int Min = min(l_min[l-1], h[l-1] - (h2[r] - r_min[r]));
			//cout << "Min =  " << Min << endl;
 			int Max = max(l_max[l-1], h[l-1] + (r_max[r] - h2[r]));
 			//cout << "Max = " << Max << endl;
			cout << Max - Min + 1 << endl;
			
		}
		
		
	}
		return 0;
}
