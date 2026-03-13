#include <iostream>
#include <random>
using namespace std;
const int MAXN = 1e3;

struct node {
  node *l;
  node *r;
  int val;
};

void insert(node* &root, int val) {
  if(!root){
    root = new node;
    root->val = val;
    root->l = root->r = nullptr;
    return;
  }
  if(val > root->val) insert(root->r, val);
  else if(val < root->val) insert(root->l, val);
}

node* search(node *root, int key) {
  if(!root) return nullptr;
  if(root->val == key) return root;
  if(key < root->val) return search(root->l, key);
  else return search(root->r, key);
}


void remove (node* &root, int k) {
  if(!root) return;
  if(root -> val != k){
    if(k < root -> val) remove(root -> l, k);
    else remove(root -> r, k);
    return;
  }
  if(!root->l && !root->r){
    delete root;
    root = NULL;
    return;
  }
  if(root->l && !root->r){
    node* temp = root;
    root = root->l;
    delete temp;
    return;
  }
  if(!root->l && root->r){
    node* temp = root;
    root = root->r;
    delete temp;
    return;
  }
  if(!(root->r->l)){
    root->val = root->r->val;
    node* temp = root->r;
    root->r = root->r->r;
    delete temp;
    return;
  }
  node* minR = root->r;
  node* parent = root;
  while(minR->l){
    parent = minR;
    minR = minR->l;
  }
  root->val = minR->val;
  parent->l = minR->r;
  delete minR;
}

void preorder(node* root) {
  if(!root) return;
  cout << root->val << " ";
  preorder(root->l);
  preorder(root->r);
}
void solve(){
  int n; cin >> n;
  node *tree = new node();
  cout << "arr: ";
  for(int i = 0; i < n; ++i){
    int x = rand() % MAXN;
    cout << x << ' ';
    insert(tree, x);
  }
  cout << "\n";
  cout << "preorder : ";
  preorder(tree);
  cout << "\n";
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