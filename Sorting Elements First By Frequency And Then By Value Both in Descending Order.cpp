#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, k;
    cin >> n >> k;
    int a[n];
    map<int, int> mp;
    for( i = 0 ; i < n ; i++ )
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    using Val = pair<int, int>;
    vector<Val>  values(mp.begin(), mp.end());
    sort(values.begin(), values.end(), [](Val const& lhs, Val const& rhs)
    {
        return ( lhs.second > rhs.second ) || ( lhs.second == rhs.second && lhs.first > rhs.first );
    });
    vector<int> result;
    result.reserve(n);
    for( auto const& val : values )
    {
        for( int loop = 0 ; loop < val.second ; ++loop )
        {
        	if( find(result.begin(), result.end(), val.first) == result.end() )
            {
            	result.push_back(val.first);
			}
        }
    }
    for( auto& it : result )
    {
        cout << it << ' ';
        if( --k == 0 )
        {
            break;
        }
    }
    return 0;
}
