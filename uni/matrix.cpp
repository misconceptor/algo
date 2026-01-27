#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <set>

#define pb push_back
#define int long long

using namespace std;
using vi = vector<int>;
using pii = pair<int,int>;
using ll = long long;

void solve(){
    int q; cin >> q;
    vi n(q), m(q);
    for(int i = 0; i < q; ++i){
        cin >> n[i] >> m[i];
    }
    vector<vi> dp(q,vi(q,0));

    for(int len = 2; len <= q; ++len){
        for(int i = 0; i + len <= q; ++i){
            int j = i + len - 1;
            dp[i][j] = LLONG_MAX;
            for(int k = i; k <= j-1; ++k){
                dp[i][j] = min(dp[i][j], (n[i] * m[k] * m[j] + dp[i][k] + dp[k+1][j]));
            }
        }
    }
    cout << dp[0][q-1] << endl;
    // for(int i = 0; i < q; i++){
    //     for(int j = 0; j < q; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--){
        solve();
    }
    return 0;
}