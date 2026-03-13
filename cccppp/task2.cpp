#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

#define fi first
#define se second
  
using namespace std;
using ll = long long;

const int inf = INT_MAX; 
  
int bs(vector<int> &v, int x){
  int l = 0, r = v.size() - 1, m;
  while(l <= r){
    m = (l + r) / 2;
    if(v[m] == x) return m;
    else if(v[m] < x) l = m + 1;
    else r = m - 1;
  }
  return -1;
}
void solve(){
  int n; cin >> n;
  vector<pair<int, int>> seg(n);
  for(auto &i : seg) cin >> i.fi >> i.se;
  int cur = seg[0].fi, len = 1, ans = 1;
  for(int i = 1; i < n; ++i){
    cur = max(cur, seg[i].fi);
    // cout << cur << ' ' << "(" << seg[i].fi << ' ' << seg[i].se << ") ";
    if(cur > seg[i].se) {
      ans = max(ans, len);
      len = 1;
      cur = seg[i].fi;
    } else {
      ++len;
    }
    // cout << len << "\n";
  }
  ans = max(ans, len);
  cout << ans << "\n";
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  int t = 1;
  // cin >> t;
  while (t--) {
    // cout << "test " << t << "\n";
    solve();
  }
  return 0;
}