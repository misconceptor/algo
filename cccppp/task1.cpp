#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

#define pb push_back
#define fi first
#define se second

using namespace std;
using vi = vector<int>;
using ll = long long;
using pii = pair<int, int>;

const int DIM = 3;

void solve(){
  int n, m; cin >> n >> m;
  vi point(n);
  vector<pii> seg(m);
  set<pii> s;
  for(int i = 0; i < n; ++i){
    cin >> point[i];
    s.insert({point[i], i});
  }
  for(auto &i : seg) cin >> i.fi >> i.se;
  vector<vi> a(n);// indices of segments for each point
  for(int i = 0; i < m; ++i){
    auto l = s.lower_bound({seg[i].fi, -1});

    while(l != s.end() && l->fi <= seg[i].se){
      int idx = l->se;
      if(a[idx].size() < DIM){
        a[idx].pb(i);
        ++l;
      } else {
        auto it = l++;
        s.erase(it);
      }
    }
  }
  for(int i = 0; i < n; ++i){
    while(a[i].size() != DIM) a[i].pb(-1);
  } 

  vector<vi> dp(n, vi(DIM, 0));
  vector<vi> prev(n, vi(DIM, -1));

  for(int i = 0; i < DIM; ++i){
    dp[0][i] = (a[0][i] != -1);
  }
  if(!(dp[0][0] || dp[0][1] || dp[0][2])){
    cout << "No\n";
    return;
  }
  prev[0][0] = prev[0][1] = prev[0][2] = -1; // prev = COLUMN in previous row

  for(int i = 1; i < n; ++i){
    bool can = false;
    for(int k = 0; k < DIM; ++k){
      if(a[i][k] == -1) continue;
      for(int j = 0; j < DIM; ++j){
        if(dp[i - 1][j] && a[i - 1][j] != a[i][k]){
          dp[i][k] = 1;
          prev[i][k] = j;
          can = true;
        }
      }
    }
    if(!can){
      cout << "No\n";
      return;
    }
  }
  int cur = -1;
  for(int i = 0; i < 3; ++i){
    if(dp[n - 1][i]) cur = i;
  }
  if(cur == -1){
    cout << "No\n";
    return;
  }
  vi ans;
  for(int i = n - 1; i >= 0; --i){
    ans.pb(a[i][cur]);
    cur = prev[i][cur];
  }
  cout << "Yes\n";
  for(int i = ans.size() - 1; i >= 0; --i) cout << ans[i] + 1 << ' ';
  cout << "\n";
}

int main(){
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  solve();
  return 0;
}