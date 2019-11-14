#include <bits/stdc++.h> 
#include <fstream>
using namespace std; 
  
// An AVL tree node  
struct node  
{  
    //public: 
    int key;  
    node *left, *right; 
    node(int _key,node * _left, node * _right): key { _key}, left{ _left }, right { _right}{}
};   
  
/* Helper function that allocates  
a new node with the given key and  
    NULL left and right pointers. */
  
// A utility function to right  
// rotate subtree rooted with y  
// See the diagram given above.  
node *rightRotate(node *x)  
{  
    node *y = x->left;  
    x->left = y->right;  
    y->right = x;  
    return y;  
}  
  
// A utility function to left  
// rotate subtree rooted with x  
// See the diagram given above.  
node *leftRotate(node *x)  
{  
    node *y = x->right;  
    x->right = y->left;  
    y->left = x;  
    return y;  
}  
  
// This function brings the key at 
// root if key is present in tree.  
// If key is not present, then it 
// brings the last accessed item at  
// root. This function modifies the 
// tree and returns the new root
void insertar(node *&t,int x){
    if(t==NULL)
        t=new node{x,NULL,NULL};
    else if(t->key > x)
        insertar(t->left,x);
    else if(x > t->key)
        insertar(t->right,x);
    else
        ;
}
node *splay(node *root, int key)  
{  
    // Base cases: root is NULL or 
    // key is present at root  
    if (root == NULL || root->key == key)  
        return root;  
  
    // Key lies in left subtree  
    if (root->key > key)  
    {  
        // Key is not in tree, we are done  
        if (root->left == NULL) return root;  
  
        // Zig-Zig (Left Left)  
        if (root->left->key > key)  
        {  
            // First recursively bring the 
            // key as root of left-left  
            root->left->left = splay(root->left->left, key);  
  
            // Do first rotation for root,  
            // second rotation is done after else  
            root = rightRotate(root);  
        }  
        else if (root->left->key < key) // Zig-Zag (Left Right)  
        {  
            // First recursively bring 
            // the key as root of left-right  
            root->left->right = splay(root->left->right, key);  
  
            // Do first rotation for root->left  
            if (root->left->right != NULL)  
                root->left = leftRotate(root->left);  
        }  
  
        // Do second rotation for root  
        return (root->left == NULL)? root: rightRotate(root);  
    }  
    else // Key lies in right subtree  
    {  
        // Key is not in tree, we are done  
        if (root->right == NULL) return root;  
  
        // Zag-Zig (Right Left)  
        if (root->right->key > key)  
        {  
            // Bring the key as root of right-left  
            root->right->left = splay(root->right->left, key);  
  
            // Do first rotation for root->right  
            if (root->right->left != NULL)  
                root->right = rightRotate(root->right);  
        }  
        else if (root->right->key < key)// Zag-Zag (Right Right)  
        {  
            // Bring the key as root of  
            // right-right and do first rotation  
            root->right->right = splay(root->right->right, key);  
            root = leftRotate(root);  
        }  
  
        // Do second rotation for root  
        return (root->right == NULL)? root: leftRotate(root);  
    }  
}  
  
// The search function for Splay tree.  
// Note that this function returns the  
// new root of Splay Tree. If key is  
// present in tree then, it is moved to root.  
node *search(node *root, int key)  
{  
    return splay(root, key);  
}  
  
// A utility function to print  
// preorder traversal of the tree.  
// The function also prints height of every node  
void preOrder(node *t,int n)  
{  
    if (t == NULL)  
    {  
        return ; 
    }
    preOrder(t->right,n+1);
    for(int i=0;n>i;i++)
    {
       cout<<"   "; 
    }
    cout<<t->key<<endl;
    preOrder(t->left,n+1);
} 
node* delete_key(struct node *root, int key) 
{ 
    node *temp; 
    if (!root) 
        return NULL; 
      
    // Splay the given key     
    root = splay(root, key); 
      
    // If key is not present, then 
    // return root 
    if (key != root->key) 
        return root; 
          
    // If key is present 
    // If left child of root does not exist 
    // make root->right as root    
    if (!root->left) 
    { 
        temp = root; 
        root = root->right; 
    } 
      
    // Else if left child exits 
    else
    { 
        temp = root; 
  
        /*Note: Since key == root->key, 
        so after Splay(key, root->lchild), 
        the tree we get will have no right child tree 
        and maximum node in left subtree will get splayed*/
        // New root 
        root = splay(root->left, key); 
          
        // Make right child of previous root  as 
        // new root's right child 
        root->right = temp->right; 
    } 
      
    // free the previous root node, that is, 
    // the node containing the key 
    delete temp; 
      
    // return root of the new Splay Tree 
    return root; 
      
}  
void recorrer(node *&p,ofstream &in)
    {
        if( p != NULL )
        {
            if(p->left)
                in<<p->key<<"->"<<p->left->key<<endl;
            if(p->right)
                in<<p->key<<"->"<<p->right->key<<endl;
            recorrer( p->left,in );
            //cout << t->key << endl;
            recorrer( p->right,in );
        }

}
 node *graficar(node * root){
        ofstream in("b.txt");
        in<<"digraph G{\n";
        recorrer(root,in);
        in<<"}";
        in.close();
        string out="dot -Tpng b.txt -o 01.png";
        char*a=&out[0];
        system(a);
        out="start 01.png";
        a=&out[0];
        system(a);
    }

  
/* Driver code*/
int main()  
{  
    ofstream l;

    struct node *root =NULL;
    insertar(root,10);
    insertar(root,11);
    insertar(root,12);
    insertar(root,13);
    insertar(root,9);
    insertar(root,8);
    insertar(root,4);
    insertar(root,3);
    insertar(root,5);
    preOrder(root,0);
    root=delete_key(root,5);
    preOrder(root,0);
    //root=graficar(root);
    return 0;  
}  
  
// This code is contributed by rathbhupendra