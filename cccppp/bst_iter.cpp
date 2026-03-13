#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

const int maxn = 8e5 + 5;
const ll mx = 1e15;

struct bst{
  struct node{
    int val;
    int l = -1, r = -1;
  };
  vector<node> t;
  int root = 0;
  bst(int val){
    t.push_back({val, -1, -1});
  } 
  void add(int v){
    int cur = root;
    while(true){
      if(v < t[cur].val){
        if(t[cur].l == -1){
          t[cur].l = t.size();
          t.push_back({v, -1, -1});
          return;
        }
      cur = t[cur].l;
      } else if(v > t[cur].val){
        if(t[cur].r == -1){
          t[cur].r = t.size();
          t.push_back({v, -1, -1});
          return;
        }
        cur = t[cur].r;
      } else return;
    }
  }
  int remove(int cur, int v){
    if(cur == -1) return -1;

    if(v < t[cur].val){
      t[cur].l = remove(t[cur].l, v);
    } else if(v > t[cur].val){
      t[cur].r = remove(t[cur].r, v);
    } else {
      if(t[cur].l == -1) return t[cur].r;
      if(t[cur].r == -1) return t[cur].l;

      int idx = t[cur].r;
      while(t[idx].l != -1) idx = t[idx].l;

      t[cur].val = t[idx].val;
      t[cur].r = remove(t[cur].r, t[idx].val);
    }
    return cur; 
  }
  
  void inorder_r(int cur){
    if(cur == -1) return;
    inorder_r(t[cur].l);
    cout << t[cur].val << ' ';
    inorder_r(t[cur].r);
  }
  void preorder_r(int cur){
    if(cur == -1) return;
    cout << t[cur].val << ' ';
    preorder_r(t[cur].l);
    preorder_r(t[cur].r);
  }
  void preorder_i(){
    stack<int> s;
    int cur = this->root, prev = -1;
    while(!s.empty() || cur != -1){
      if(cur == -1){
        prev = s.top();
        s.pop();
        cur = t[prev].r;
      } else {
        s.push(cur);
        cout << t[cur].val << ' ';
        cur = t[cur].l;
      }
    }
    cout << "\n";
  }
  void inorder_i(){
    stack<int> s;
    int cur = this->root, prev = -1;
    while(!s.empty() || cur != -1){
      if(cur == -1){
        prev = s.top();
        cout << t[prev].val << ' ';
        s.pop();
        cur = t[prev].r;
      } else {
        s.push(cur);
        cur = t[cur].l;
      }
    }
    cout << "\n";
  }
  void postorder_r(int cur){
    if(cur == -1) return;
    postorder_r(t[cur].l);
    postorder_r(t[cur].r);
    cout << t[cur].val << ' ';
  }
  void postorder_i(){
    stack<int> s;
    int cur = this->root, prev = -1;
    while(!s.empty() || cur != -1){
      if(cur != -1){
        s.push(cur);
        cur = t[cur].l;
      } else {
        int top = s.top();
        if(t[top].r != -1 && prev != t[top].r){
          cur = t[top].r;
        } else {
          cout << t[top].val << ' ';
          prev = top;
          s.pop();
        }
      }
    }
    cout << "\n";
  }
};

void solve(){
  int n;
  cin >> n;
  bst t(n);
  while(cin >> n) t.add(n);
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  solve();
  return 0;
}