#include<bits/stdc++.h>


using namespace std;
#define ll long long
#define MAXN 300010


int a[MAXN];
int t;
int n;
ll subs[40];
ll pluss[40];


class Trie{
public:
	Trie* nxt[2];
	ll plus;
	ll sub;
	ll cnt;
	Trie()
	{
		nxt[0] = nxt[1] = NULL;
		plus = cnt = sub = 0;
	}
	~Trie()
	{
		for(int i = 0; i <= 1; ++i)
		{
			if(nxt[i] != NULL)
			{
				delete nxt[i];
				nxt[i] = NULL;
			}
		}
	}
	void push(int x)
	{
		Trie* tmp = this;
		for(int k = 30; k >= 0; --k)
		{
			int i = (x >> k) & 1;
			if(tmp->nxt[i] == NULL)
			{
				tmp->nxt[i] = new Trie();
			}
			int j = 1 - i;
			if(i == 0)
			{
				int cnt2 = (tmp->nxt[j] == NULL) ? 0 : tmp->nxt[j]->cnt;
				tmp->sub += cnt2;
			}
			else
			{
				int cnt2 = (tmp->nxt[j] == NULL) ? 0 : tmp->nxt[j]->cnt;
				tmp->plus += cnt2;
			}
			tmp->cnt++;
			tmp = tmp->nxt[i];
		}
		tmp->cnt++;
	}
	void dfs(int dep)
	{
		//cout<<"dfs dep = "<<dep<<endl;
		subs[dep] += sub;
		pluss[dep] += plus;
		if(dep == 0)
			return;
		if(nxt[0] != NULL)
		{
			nxt[0]->dfs(dep-1);
		}
		if(nxt[1] != NULL)
		{
			nxt[1]->dfs(dep-1);
		}
	}
};

int main()
{
	cin>>n;
	Trie* trie = new Trie();
	for(int i = 1; i <= n; ++i)
	{
		cin>>a[i];
		//cout<<"jjjj"<<endl;
		trie->push(a[i]);
	}
	for(int k = 0; k < 31; ++k)
	{
		subs[k] = pluss[k] = 0;
	}
	trie->dfs(30);
	int x = 0;
	ll ans = 0;
	for(int k = 30; k >= 0; --k)
	{
		//cout<<"subs["<<k<<"] = "<<subs[k]<<endl;
		//cout<<"pluss["<<k<<"] = "<<pluss[k]<<endl;
		if(subs[k] <= pluss[k])
		{
			ans += subs[k];
		}
		else
		{
			ans += pluss[k];
			x |= (1 << k);
		}
	}
	cout<<ans<<" "<<x<<endl;
	delete trie;
	
}
