#include <iostream>
#include <random>

using namespace std;
using ll = long long;

const int MAXN = 1e3;


struct bst{
    struct node {
        node *l, *r, *p;
        int val, depth;
        node(int x, node *prev = nullptr) : val(x), depth(0), l(nullptr), r(nullptr), p(prev) {}
    };
    node *root;
    bst(int x) {
        root = new node(x);
    }

    void add(node* &cur, int x, node* prev = nullptr){
        if(!cur){
            cur = new node(x, prev);
            cur->depth = (prev ? 1 + prev->depth : 0);
            return;
        }
        if(x > cur->val) add(cur->r, x, cur);
        else if(x < cur->val) add(cur->l, x, cur);
    }
    node* find(node *root, int x) {
        if(!root) return nullptr;
        if(root->val == x) return root;
        if(x < root->val) return find(root->l, x);
        else return find(root->r, x);
    }

    void remove(node* &cur, int k) {
        if(!cur) return;
        if(k < cur->val) remove(cur->l, k);
        else if(k > cur->val) remove(cur->r, k);
        else {
            if(!cur->l){
                node* temp = cur->r;
                if(temp) temp->p = cur->p;
                delete cur;
                cur = temp;
            } else if(!cur->r){
                node* temp = cur->l;
                if(temp) temp->p = cur->p;
                delete cur;
                cur = temp;
            } else if(!(cur->r && cur->l)){
                node* next = cur->r;
                while(next->l) next = next->l;
                cur->val = next->val;
                remove(cur->r, next->val);
            }
        }
    }
    void inorder(node* cur) {
        if(!cur) return;
        inorder(cur->l);
        cout << cur->val << " " << cur->depth << '\n';
        inorder(cur->r);
    }
    void preorder(node* cur) {
        if(!cur) return;
        cout << cur->val << " " << cur->depth << '\n';
        inorder(cur->r);
        preorder(cur->l);
        preorder(cur->r);
    }
    void path(node *src, node *dest){

    }
};

void solve(){
    int n; cin >> n;
    int x; cin >> x;
    bst t(x);
    for(int i = 0; i < n - 1; ++i){
        cin >> x;
        t.add(t.root, x);
    }
    t.inorder(t.root); 
    cout << '\n';
    // t.remove(t.root, 11);
    // t.inorder(t.root); 
    // cout << '\n';
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  int t = 1;
  //cin >> t;
  while(t--) solve();
  return 0;
}
