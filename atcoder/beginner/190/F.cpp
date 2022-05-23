#include <bits/stdc++.h>



using namespace std;

int N;
int A[300010];
int AA[300010];
int tmp[300010];
#define ll long long

ll merge_sort(int low, int high)
{
	if (low == high)
	{
		return 0;
	}
	int mid = (low + high) >> 1;
	ll a1 = merge_sort(low, mid);
	ll a2 = merge_sort(mid+1, high);
	int i1 = low;
	int i2 = mid+1;
	int i = 0;
	ll ans = a1 + a2;
	while(i1 <= mid || i2 <= high)
	{
		if(i1 > mid)
		{
			tmp[i++] = AA[i2++];
		}
		else if(i2 > high)
		{
			tmp[i++] = AA[i1++];
		}
		else
		{
			if(AA[i1] < AA[i2])
			{
				tmp[i++] = AA[i1++];
			} else {
				tmp[i++] = AA[i2++];
				ans += (mid - i1 + 1);
			}
		}
	}
	for(int j = low; j <= high; ++j)
		AA[j] = tmp[j - low];
	return ans;
}

int main()
{
	cin >> N;
	for(int i = 0; i < N; ++i)
	{
		cin >> A[i];
		AA[i] = A[i];
	}
	ll ans = 0;
	
	ans = merge_sort(0, N-1);
	cout << ans << endl;
	for(int k = 1; k < N; ++k)
	{
		ans -= A[k-1];
		ans += (N-1-A[k-1]);
		cout << ans <<endl;
	}
	
}
