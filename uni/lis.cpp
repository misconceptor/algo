#include <iostream>
#include <climits>
#include <chrono>
#include <algorithm>
#include <vector>
#include <math.h>

#define pb push_back
#define fi first
#define se second
// #define int long long

using namespace std;
using vi = vector<int>;
using pii = pair<int,int>;
using ll = long long;

const int MAXN = 1e9 + 7;

int ub(vi &v, int x){
    int l = 0, r = v.size() - 1, m;
    while(l <= r){
        int m = (l + r) / 2;
        if(v[m] <= x) l = m + 1;
        else r = m - 1;
    }
    return l;
}

void solve(){
    int n; cin >> n;
    vi a(n);
    for(auto &i : a) cin >> i;
    // cout << "arr:\n";
    // for(auto i : a) cout << i << ' '; 
    // cout << endl;
    vi d(n+1,MAXN);
    d[0] = -MAXN;
    for(int i = 0; i < n; ++i){
        int l = ub(d, a[i]);
        if(d[l-1] < a[i] && a[i] < d[l]){
            d[l] = a[i];
        }

    } 
    int ans = 0;
    for(int i = 0; i <= n; ++i){
        if(d[i] < MAXN) ans = i;
    }
    cout << ans << endl;
    // for(auto i : d) cout << i << ' ';
    // cout << endl;
    
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--){
        solve();
    }
    return 0;
}
    // int n = 7e5;
    // for(int i = 0; i < n; ++i){
    //     cout << 10 << endl;
    //     cout << "10 9 8 7 6 5 4 3 2 1 \n";
    // }
    // return 0;
    // auto start = std::chrono::high_resolution_clock::now();    
    // auto end = std::chrono::high_resolution_clock::now();
    // auto d = (std::chrono::duration_cast<std::chrono::milliseconds>(end-start));
    // cout << "time: " << d.count() << endl;