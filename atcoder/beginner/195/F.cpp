#include <bits/stdc++.h>


using namespace std;
#define ll long long

ll A, B;

vector<ll> factors(ll n)
{
	vector<ll> ret;
	ll sqt = sqrt(n);
	ll i = 2;
	while(i <= sqt)
	{
		if(n % i == 0)
		{
			ret.push_back(i);
			while(n % i == 0)
				n /= i;
		}
		if (i == 2)
			++i;
		else
			i += 2;
	}
	if (n != 1)
		ret.push_back(n);
	return ret;
}

vector<ll> facs[80];
vector<ll> primes;
int main()
{
	cin >> A >> B;
	map<ll, int> prime_map;
	int nxt_val = 0;
	for(ll n = A; n <= B; ++n)
	{
		facs[n-A] = factors(n);
		for(ll p: facs[n-A])
		{
			if(prime_map.count(p) == 0)
			{
				prime_map[p] = nxt_val;
				primes.push_back(p);
				nxt_val++;
			}
		}
	}
	cout << "nxt_val = " << nxt_val << endl;
	
}
