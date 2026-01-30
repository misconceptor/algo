// #pragma GCC target("avx2")
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

#define pb push_back
#define fi first
#define se second

using namespace std;
using vi = vector<int>;
using pii = pair<int,int>;
using ll = long long;

const ll BASE = 1e9;
const ll MAXLEN = 15;

struct bignum{
    ll d[MAXLEN];
    int len;

    void set(ll v) {
        for(int i=0; i<MAXLEN; ++i) d[i] = 0;
        d[0] = v;
        len = (v > 0);
    }

    void add(const bignum& other) {
        ll carry = 0;
        int max_l = max(len, other.len);
        for(int i = 0; i < max_l || carry; ++i) {
            ll cur = d[i] + carry + (i < other.len ? other.d[i] : 0);
            if(cur >= BASE) {
                d[i] = cur - BASE;
                carry = 1;
            } else {
                d[i] = cur;
                carry = 0;
            }
            if(i >= len) len = i + 1;
        }
    }
};

bignum dp[2][1024];
int adj[1024][1024];
int adj_idx[1024];

/*
adj[1024][1024]: 
This is a 2D array where each row represents a bitmask.
 For a specific mask i, the row adj[i] contains all other masks 
 that can safely stand next to it without forming a 2×2 square.

adj_idx[1024] This is a 1D array that stores the count of valid neighbors for each mask.
*/


void solve(){
    int n, m;
    cin >> n >> m;
    if(n < m) swap(n, m); 
    int num = (1 << m);

    for(int i = 0; i < num; ++i){
        adj_idx[i] = 0;
        for(int j = 0; j < num; ++j){
            bool ok = true;
            for(int k = 0; k < m - 1; ++k) {
                if(((i >> k) & 1) == ((i >> (k + 1)) & 1) && 
                    ((i >> (k + 1)) & 1) == ((j >> k) & 1) && 
                    ((j >> k) & 1) == ((j >> (k + 1)) & 1))
                { 
                    ok = false; 
                    break; 
                }
            }
            if(ok){
                adj[i][adj_idx[i]] = j;
                ++adj_idx[i];
            }
            
        }
    }
    for(int j = 0; j < num; ++j){
        dp[0][j].set(1);
    }

    int cur = 0;
    for(int i = 1; i < n; ++i) {
        int next = 1 - cur;

        for(int j = 0; j < num; ++j) dp[next][j].set(0);

        for(int mask = 0; mask < num; ++mask) {
            for(int k = 0; k < adj_idx[mask]; ++k) {
                int prev= adj[mask][k];
                dp[next][mask].add(dp[cur][prev]);
            }
        }
        cur = next;
    }

    bignum ans;
    ans.set(0);
    for(int j = 0; j < num; ++j){
        ans.add(dp[cur][j]);
    }

    cout << ans.d[ans.len - 1];
    for(int i = ans.len - 2; i >= 0; --i) {
        cout << setfill('0') << setw(9) << ans.d[i];
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--){
        solve();
    }
    return 0;
}