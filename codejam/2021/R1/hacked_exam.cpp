#include <bits/stdc++.h>


using namespace std;
#define ll __int128_t
int T;
int N, Q;
string A[4];
int S[4];
int Tr[200];
int Fa[200];
int possi;

ll GCD(ll a,ll b){           // 求最大公约数
    ll temp=0;
    while(b!=0){
        temp=a;
        a=b;
        b=temp%b;
    }
    return a;
}

ll LCM(ll a, ll b){
	ll gcd = GCD(a, b);
	return a * b / gcd;
}

class Fs{
	public:
	Fs(ll up_, ll down_){
		up = up_;
		down = down_;
	}	
		ll up;
		ll down;

	
};

Fs add(Fs& a, Fs& b)
{
	ll down = LCM(a.down, b.down);
	ll up = a.up * (down / a.down) + b.up * (down / b.down);
	ll gcd = GCD(up, down);
	down /= gcd;
	up /= gcd;
	return Fs(up, down);
}

map<vector<int>, pair<ll, vector<ll>> > mem;

pair<ll, vector<ll>> dfs(int i, vector<char>& ans, vector<int>& score)
{
	vector<int> key;
	key.push_back(i);
	for(int j: score){
		key.push_back(j);
	}
	if (mem.find(key) != mem.end())
		return mem[key];
	vector<ll> val(Q, 0);
	ll cnt = 0;
	if(i == Q)
	{
		++possi;
		for(int j = 0; j < N; ++j)
		{
			if(score[j] != S[j])
				return make_pair(0, vector<ll> ());
		}
		
		
		//std::cout << endl;
		return make_pair(1, val);
	}
	bool ok = true;
	for(int j = 0; j < N; ++j)
	{
		if(A[j][i] == 'T' && score[j] == S[j])
		{
			ok = false;
			break;
		}
	}
	if(ok)
	{
		ans.push_back('T');
		auto score2 = score;
		for(int j = 0; j < N; ++j)
			if(A[j][i] == 'T')
				++score2[j];
		auto p = dfs(i+1, ans, score2);
		ans.pop_back();
		if (p.first > 0)
		{
			val = p.second;
			cnt += p.first;
			val[i] += p.first;
		}
	}
	ok = true;
	for(int j = 0; j < N; ++j)
	{
		if(A[j][i] == 'F' && score[j] == S[j])
		{
			ok = false;
			break;
		}
	}
	if(ok)
	{
		ans.push_back('F');
		auto score2 = score;
		for(int j = 0; j < N; ++j)
			if(A[j][i] == 'F')
				++score2[j];
		auto p = dfs(i+1, ans, score2);
		ans.pop_back();
		if (p.first > 0)
		{
			for(int j = 0; j < Q; ++j)
				val[j] += p.second[j];
			cnt += p.first;
		}
	}
	mem[key] = make_pair(cnt, val);
	return make_pair(cnt, val);
}
int main()
{
	cin >> T;
	for(int t = 1; t <= T; ++t)
	{
		cin >> N >> Q;
		mem.clear();
		for(int i = 0; i < N; ++i)
		{
			cin >> A[i];
			cin >> S[i];
		}
		for(int i = 0; i < Q; ++i)
			Tr[i] = Fa[i] = 0;
		vector<char> ans;
		vector<int> score;
		for(int i = 0; i < N; ++i)
			score.push_back(0);
		// dfs(0, ans, score);
		auto p = dfs(0, ans, score);
		ll total = p.first;
		vector<ll>& tr = p.second;
		std::cout << "Case #" << t << ": ";
		ll up = 0;
		for(int i = 0; i < Q; ++i)
		{
			up += max(tr[i], total - tr[i]);
		}
		int gcd = GCD(up, total);
		for(int i = 0; i < Q; ++i)
		{
			if(tr[i] > total - tr[i])
				cout << 'T';
			else
				cout << 'F';
		}
		up /= gcd;
		total /= gcd;
		cout << " ";
		cout << (long long)up << "/" << (long long)total << endl;
	}
	
	
}
