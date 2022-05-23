#include <bits/stdc++.h>


using namespace std;
#define ll long long

const ll base1=131;
const ll base2=13331;
const ll mod1=998244353;
const ll mod2=1e9+7;



#define MAXN 100010
int T;
int N;
string words[MAXN];
int ans;
unordered_map<ll, bool> map1;
unordered_map<ll, bool> map2;



void sol(string& word)
{
	ll h1 = 0, h2 = 0;
	bool found = false;
	for(int i = 0; i < (int)word.size(); ++i)
	{
		h1 = (h1 * base1 + (word[i] - 'a')+1) % mod1;
		h2 = (h2 * base2 + (word[i] - 'a')+1) % mod2;
		if(!found && (map1.count(h1) == 0 || map2.count(h2) == 0))
		{
			ans += (i + 1);
			found = true;
		}	
		map1[h1] = true;
		map2[h2] = true;
	}
	if(!found)
	{
		ans += (int)word.size();
	}
	return;
}

int main()
{cin.sync_with_stdio(false);
	cin>>T;
	for(int t = 1; t <= T; ++t)
	{
		cin>>N;
		map1 = unordered_map<ll, bool> ();
		map2 = unordered_map<ll, bool> ();
		for(int i = 0; i < N; ++i)
			cin>>words[i];
		ans = 0;
		for(int i = 0; i < N; ++i)
		{
			sol(words[i]);
		}
		cout<<"Case #"<<t<<": "<<ans<<endl;
	}
	
	
}
