#include <bits/stdc++.h>

using namespace std;

#define ll long long
int T;
ll N, S, K;
int main()
{
    cin>>T;
    for(int t = 1; t <= T; ++t)
    {
        cin>>N>>K>>S;
        ll ans = min(K-1+1+N, K-1+(K-S)+N-S+1);
        cout<<"Case #"<<t<<": "<<ans<<endl;
    }
    
    
}
