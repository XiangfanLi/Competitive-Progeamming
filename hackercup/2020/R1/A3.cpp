
#include <bits/stdc++.h>

using namespace std;
#define ll long long

const ll mod = (ll)(1e9+7);

#define MAXN 1000010
int T;
int N, K;

ll AL, BL, CL, DL;
ll AW, BW, CW, DW;
ll AH, BH, CH, DH;
ll L[MAXN];
ll W[MAXN];
ll H[MAXN];

ll overlap(ll l1, ll r1, ll l2, ll r2)
{
	ll l = max(l1, l2);
	ll r = min(r1, r2);
	if(l < r)
		return r - l;
	else
		return 0;

}

int main()
{
    cout << "Hello world" << endl;
	ios::sync_with_stdio(false);
	cin>>T;
	//cout<<"T = "<<T<<endl;
	for(int tt = 1; tt <= T; ++tt)
	{
		cin>>N>>K;
		//cout<<"N = "<<N<<endl;
		for(int i = 1; i <= K; ++i)
		{
			cin>>L[i];
		}
		cin>>AL>>BL>>CL>>DL;
		for(int i = 1; i <= K; ++i)
		{
			cin>>W[i];
		}
		cin>>AW>>BW>>CW>>DW;
		for(int i = 1; i <= K; ++i)
		{
			cin>>H[i];
		}
		cin>>AH>>BH>>CH>>DH;
		for(int i = K + 1; i <= N; ++i)
		{
			L[i] = ((AL*L[i-2]+BL*L[i-1]+CL) % DL) + 1;
			W[i] = ((AW*W[i-2]+BW*W[i-1]+CW) % DW) + 1;
			H[i] = ((AH*H[i-2]+BH*H[i-1]+CH) % DH) + 1;
		}
		set<pair<pair<ll, ll>, ll> > Set;
		ll ans = 2 * (H[1] + W[1]);
		ll last = 2 * (H[1] + W[1]);
		Set.insert(make_pair(make_pair(L[1], L[1] + W[1]), H[1]));
		for(int i = 2; i <= N; ++i)
		{
			//cout<<"L[i] = "<<L[i]<<endl;
			//cout<<"H[i] = "<<H[i]<<endl;
			//cout<<"W[i] = "<<W[i]<<endl;
			ll curr = 2 * (W[i] + H[i]) % mod;
			//cout<<"curr = "<<curr<<endl;
			set<pair<pair<ll, ll>, ll> >::iterator start, end;
			start = Set.lower_bound(make_pair(make_pair(L[i], -1), -1));
			if(start != Set.begin())
			{
				start--;
				if(start->first.second < L[i])
					++start;
			}
			ll left = L[i];
			/*
			if(start != Set.end())
				left = min(start->first, L[i]);
			*/
			end = Set.lower_bound(make_pair(make_pair(L[i]+W[i]+1, -1), -1));
			ll right = L[i] + W[i];
			/*
			if(end != Set.begin())
			{
				auto eend = end;
				eend--;
				right = max(right, eend->second);
			}
			* */
			//int cnt = 0;
			vector<pair<pair<ll, ll>, ll> > v;
			for(auto iter = start; iter != end;)
			{
				//++cnt;
				curr -= 2 * overlap(iter->first.first, iter->first.second, L[i], L[i] + W[i]);
				curr %= mod;
				curr += mod;
				curr %= mod;
				v.push_back(*iter);
				//cout<<iter->first<<" "<<iter->second<<endl;
				//cout<<"overlap = "<<overlap(iter->first, iter->second, L[i], L[i] + W[i])<<endl;
				Set.erase(iter++);
			}
			if(!v.empty())
			{
				for(int j = 0; j < (int)v.size(); ++j)
				{
					if(i > 0 && v[j].first.first == v[j-1].first.second)
					{
						curr -= max(v[j].second, v[j-1].second) - min(v[j].second, v[j-1].second);
					}
					else
					{
						curr -= v[j].second;
					}
					curr = (curr + mod) % mod;
					if(j < (int)v.size()-1 && v[j].first.second == v[j+1].first.first)
					{
						curr -= max(v[j].second, v[j+1].second) - min(v[j].second, v[j+1].second);
					}
					else
					{
						curr -= v[j].second;
					}
					curr = (curr + mod) % mod;
				}
				if(v[0].first.first < L[i])
				{
					Set.insert(make_pair(make_pair(v[0].first.first, L[i]), v[0].second));
				}
				if(v.back().first.second > L[i] + W[i])
				{
					Set.insert(make_pair(make_pair(v.back().first.second, L[i] + W[i]), v.back().second));
				}
			}
			/*
			if(cnt == 0)
			{

			}
			else if(cnt == 1)
			{
				curr -= 2 * H[i];
				curr = (curr%mod + mod) % mod;
			}
			else
			{
				curr -= (2 * (cnt - 2) + 4) * H[i];
				curr = (curr%mod + mod) % mod;
			}
			* */
			last += curr;
			last = ((last % mod)+mod) % mod;
			//cout<<"i = "<<i<<", "<<"last = "<<last<<endl;
			ans = ((ans * last) % mod + mod) % mod;
			//cout<<"last = "<<last<<endl;
			Set.insert(make_pair(make_pair(left, right), H[i]));
			//ans = (ans + mod) % mod;
		}

		cout<<"Case #"<<tt<<": "<<ans<<endl;
	}

}
