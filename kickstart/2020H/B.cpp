#include <bits/stdc++.h>


using namespace std;

#define ll long long

ll p5[30];
int T;
ll L, R;

ll sol1(int digit) {
    ll ans = 1;
    for(int i = 1; i <= digit; ++i)
    {
        if(i % 2 == 0)
            ans *= 5;
        else
            ans *= 5;
    }
    return ans;
}

ll sol2(vector<int>& v1, vector<int>& v2, int i, bool small) {
    if(i >= (int)v1.size())
        return 1;
    if(!small) {
        return p5[(int)v1.size() - i];
    }
    else
    {
        ll ret = 0;
        for(int j = v1[i]; j <= v2[i]; ++j) {
            if(j % 2 == i % 2)
                continue;
            if(j == v2[i])
                ret += sol2(v1, v2, i + 1, true);
            else
                ret += sol2(v1, v2, i + 1, false);
        }
        return ret;
    }
}
int digit(ll N) {
    int x = 0;
    while(N) {
        N /= 10;
        ++x;
    }
    return x;
}

ll sol(ll N) {
    if(N == 0)
        return 0;
    int d = digit(N);
    vector<int> v1(d);
    vector<int> v2(d);
    v1[0] = 1;
    for(int i = 1; i < d; ++i)
        v1[i] = 0;
    ll NN = N;
    for(int i = d-1; i >= 0; --i)
    {
        v2[i] = NN % 10;
        NN /= 10;
    }
    ll ret = 0;
    for(int dd = 1; dd < d; ++dd)
    {
        ret += p5[dd];
    }
    ret +=sol2(v1, v2, 0, true);
    return ret;
}


int main()
{
    cout << "Hello World !!" << endl;
    
    p5[0] = 1;
    for(int i = 1; i <=18; ++i)
    {
        p5[i] = p5[i-1] * 5;
    }
    cin>>T;
    for(int t = 1; t <= T; ++t) {
        cin>>L>>R;
        ll a1 = sol(L - 1);
        ll a2 = sol(R);
        ll ans = a2 - a1;
        cout<<"Case #"<<t<<": "<<ans<<endl;
    }
}
