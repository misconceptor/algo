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
    solve();
  }
  return 0;
}