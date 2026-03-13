
struct node
{
    int w;
    node *left;
    node *right;
    //node() : w(-1e9), left(nullptr), right(nullptr) {}
};

void insert(node* &tree, int val)
{
    if (tree == NULL)
    {
        tree = new node;
        tree->w = val;
        tree->left = tree->right = NULL;
        return;
    }
    
    if (val > tree->w)
        insert(tree->right, val);
    else if (val < tree->w)
        insert(tree->left, val);
}

node* search(node *tree, int key)
{
    if (tree == NULL)
        return NULL;
    if  (tree -> w == key)
        return tree;
    if (key < tree -> w)
        return search(tree -> left, key);
    else
        return search(tree -> right, key);
}


void remove (node* &tree, int k)//right remove
{
    if (tree == NULL)
        return;
    if (tree -> w != k){
        if (k < tree -> w)
            remove(tree -> left, k);
        else
            remove(tree -> right, k);
        return;
    }

    if (tree -> left == NULL && tree -> right == NULL){
        delete tree;
        tree = NULL;
        return;
    }
    //
    if (tree -> left != NULL && tree -> right == NULL){
        node* temp = tree;
        tree = tree->left;
        delete temp;
        return;
    }
    if (tree -> left == NULL && tree -> right != NULL){
        node* temp = tree;
        tree = tree->right;
        delete temp;
        return;
    }
    //
    if (tree -> right -> left == NULL){
        tree->w = tree->right->w;
        node* temp = tree->right;
        tree->right = tree->right->right;
        delete temp;
        return;
    }
    node* minR = tree->right;
    node* parent = tree;
    
    while (minR->left != NULL) {
        parent = minR;
        minR = minR->left;
    }
    tree->w = minR->w;
    parent->left = minR->right;
    delete minR;
}

void left_print(node* root) {
    if(root == NULL)
        return;
    fout << root->w << endl;
    left_print(root->left);
    left_print(root->right);
}
