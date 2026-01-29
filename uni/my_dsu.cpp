#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>

#define pb push_back
#define fi first
#define se second

using namespace std;
using vi = vector<int>;
using pii = pair<int,int>;
using ll = long long;

struct dsu{
    int n, components;
    vector<int> p, s;

    dsu(int _n) {
        n = components = _n;
        s.assign(n, 1);
        p.resize(n);
        iota(p.begin(),p.end(),0);
    }

    int root(int a){
        if(p[a] == a) return a;
        return (p[a] = root(p[a]));
    }

    void unite(int a, int b){
        if((a = root(a)) == (b = root(b))) return;

        if(s[a] < s[b]) swap(a, b);
        p[b] = a;
        s[a] += s[b];
        --components;
    }
    void compress(){
        for(int i = 0; i < n; ++i) root(i);
    }
    bool connected(int a, int b){
        return root(a) == root(b);
    }
    int size(int a){ //size of component of a
        return s[root(a)];
    }
    // void print_size(){
    //     cout << "size: ";
    //     for(auto i : s) cout << i << ' ';
    //     cout << endl;
    // }
    // void print_par(){
    //     cout << "parents : ";
    //     for(auto i : p) cout << i << ' ';
    //     cout << endl;
    // }
};

void solve(){
    dsu d(10);
    d.unite(1,2);
    d.unite(4,5);
    cout << d.components << '\n';
    cout << d.connected(1,4) << '\n';
    d.unite(1,4);
    cout << d.components << '\n';
    cout << d.connected(1,4) << '\n';
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