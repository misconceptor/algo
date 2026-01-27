#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#define pb push_back
#define fi first
#define se second

using namespace std;
using vi = vector<int>;
using pii = pair<int,int>;
using ll = long long;

struct dsu{
    int n, components;
    vector<int> p;
    vector<int> h;

    dsu(int _n) {
        n = components = _n;
        p.resize(n);
        h.assign(n, -1);
        iota(p.begin(), p.end(), 0);
    }

    int leader(int v){
        return p[v] == v ? v : leader(p[v]);
    }

    bool unite(int u, int v){
        u = leader(u);
        v = leader(v);
        if(u == v){
            return false;
        }
        if(h[u] > h[v]) swap(u, v);
        h[v] = max(h[v], h[u] + 1);
        p[u] = v;
        --components;
        return true;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; 
    cin >> n >> m;
    dsu d(n);
    vi ans;
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        d.unite(u, v);
        ans.pb(d.components);
    }
    for(auto i : ans) cout << i << endl; 
    return 0;
}