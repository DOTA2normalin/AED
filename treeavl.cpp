#include <iostream>
#include <cstdlib>
using namespace std;

struct node{
    struct node *left;
    struct node *right;
    int dato;
    int height;
    node(node *_left,node * _right, int _dato,int _height=0)
    {
        left= _left;
        right= _right;
        dato= _dato;
        height= _height;
    }

};


int height(node *t)
{
    return t==nullptr? -1: t->height;
}
void rotateleft(node *&k3)
{
    node *k2=k3->left;
    k3->left=k2->right;
    k2->right=k3;
    k3->height=max(height(k3->left),height(k3->right))+1;
    k2->height=max(height(k2->left),k3->height)+1;
    k3=k2;
}
void rotateright(node *&k3)
{
    node *k2=k3->right;
    k3->right=k2->left;
    k2->left=k3;
    k3->height=max(height(k3->right),height(k3->left))+1;
    k2->height=max(height(k2->right),k3->height)+1;
    k3=k2;
}
void doblerotateleft(node *&k3)
{
    rotateright(k3->left);
    rotateleft(k3);
}
void doblerotateright(node *&k3)
{
    rotateright(k3->right);
    rotateleft(k3);
}

void balance(node *&t)
{
    if(t==nullptr)
        return;
    if(height(t->left)-height(t->right)>1)
    {
        if(height(t->left->left)>=height(t->left->right))
        {
            rotateleft(t);
        }
        else
        {
            doblerotateleft(t);
        }
    }
    else if(height(t->right)-height(t->left)>1)
    {
        if(height(t->right->right)>=height(t->right->left))
        {
            rotateright(t);
        }
        else
        {
            doblerotateright(t);
        }
    }
    t->height=max(height(t->left),height(t->right))+1;
    
}

void insertar(node *&t,int x)
{
    if(t==nullptr)
        t=new node{nullptr,nullptr,x};
    else if(t->dato > x)
    {
        insertar(t->left,x);
    }
    else if(t->dato < x)
    {
        insertar(t->right,x);
    }
    else
    {
        return ;
    }
    balance(t);
}
node * findMin(node*&t)
{
    if(t==nullptr)  
        return nullptr;
    else if(t->left==nullptr)
        return t;
    return findMin(t->left);
}
void remove(node *&t,int x)
{
    if(t==nullptr)
        return ;
    if(t->dato < x)
        remove(t->right , x );
    else if(t->dato > x)
        remove(t->left , x );
    else if(t->left!=nullptr && t->right!=nullptr)
    {
        t->dato=findMin(t->right)->dato;
        remove(t->right, t->dato);
    }
    else
    {
        node* oldnodo=t;
        t=(t->left!=nullptr)? t->left :t->right;
        delete oldnodo;
    }
    
    balance(t);
}

void print(node *t,int contador)
{
    if(t==nullptr)
        return ;
    print(t->right,contador+1);

    for(int i=0;i<contador;i++)
    {
        cout<<"   ";
    }
    cout<<t->dato<<endl;

    print(t->left,contador+1);
}
int main() 
{
    node *root=nullptr;
    insertar(root,10);
    insertar(root,11);
    insertar(root,12);
    insertar(root,13);
    insertar(root,14);
    insertar(root,15);
    insertar(root,16);
    insertar(root,17);

    print(root,0);
    remove(root,15);
    cout<<endl;
    cout<<endl;
    cout<<endl;
    print(root,0);
    return 0;   
}
