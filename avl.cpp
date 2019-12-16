#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
static int contador;
//Class NodeAVL
struct NodeAVL{
        int dato;
        struct NodeAVL *left;
        struct NodeAVL *right;
        int height;
        NodeAVL( const int _dato, NodeAVL * _left,NodeAVL * _right, int _height=0)
        :dato{ _dato}, left{ _left }, right { _right}, height { _height} {}
        NodeAVL( int && _dato , NodeAVL * _left,NodeAVL * _right, int _height=0)
        :dato{ std::move(_dato)}, left{ _left }, right { _right}, height { _height} {}
};
NodeAVL * findMin(NodeAVL *t)
{
    if( t == nullptr )
        return nullptr;
    if( t->left == nullptr )
        return t;
    return findMin( t->left );
}
bool buscar(NodeAVL *t,int x)
{
    if(t==nullptr)
        return false;
    if(t->dato == x)
        return true;
    
    else if(t->dato == x)
        return true;
    buscar(t->left,x);
    buscar(t->right,x);
    
}

void auxContador(NodeAVL*& nodo, int *c)
{
   (*c)++;
   if(nodo->left) auxContador(nodo->left, c);
   if(nodo->right)   auxContador(nodo->right, c);
}  

int NumeroNodos(NodeAVL * a, int *contador)
{
   *contador = -1;

   auxContador(a, contador); /* Función auxiliar */
   return *contador;
}

int height(NodeAVL *t)
{
    return t==nullptr ? -1: t->height;
}   
void rotateWithLeftChild(NodeAVL *& k2)
{
    NodeAVL *k1=k2->left;
    k2->left= k1->right;
    k1->right= k2;
    k2->height= max(height(k2->left),height(k2->right))+1;
    k1->height= max(height(k1->left), k2->height)+1;
    k2=k1;
}

void rotateWithRightChild(NodeAVL *& k2)
{
    NodeAVL *k1=k2->right;
    k2->right= k1->left;
    k1->left= k2;
    k2->height= max(height(k2->right),height(k2->left))+1;
    k1->height= max(height(k1->right), k2->height)+1;
    k2=k1;
}

void doubleWithLeftChild(NodeAVL *& k3)
{
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
}

void doubleWithRightChild(NodeAVL *&k3)
{
    rotateWithRightChild(k3->right);
    rotateWithLeftChild(k3);
}
void balanceo(NodeAVL *&t)
{
    if(t==nullptr)
        return;
    if(height(t->left)-height(t->right)>1)
    {
        if(height(t->left->left)>=height(t->left->right))
            rotateWithLeftChild(t);
        else
            doubleWithLeftChild(t);
        
    }
    else if(height(t->right)-height(t->left)>1)
    {
        if(height(t->right->right)>= height(t->right->left))
            rotateWithRightChild(t);
        else
            doubleWithRightChild(t);
        
    }
    t->height=max(height(t->left),height(t->right))+1;

}

void insertar(const int &x,NodeAVL *&t)
{
    if (t==nullptr)
        t=new NodeAVL{x,nullptr,nullptr};
    else if(t->dato> x)
        insertar(x,t->left);
    else if(t->dato< x)
        insertar(x,t->right);
    else
    {
        return ;
    }
    balanceo(t);    
}
void remove(const int &x, NodeAVL *& t)
{
    if(t==nullptr)
        return ;
    if(x< t->dato)
        remove(x,t->left);
    else if (t->dato < x)
    {
        remove(x,t->right);
    }
    else if(t->left !=nullptr && t->right !=nullptr)
    {
        t->dato =findMin(t->right)->dato;
        remove(t->dato,t->right);
    }
    else
    {
        NodeAVL *oldNode=t;
        t=(t->left!=nullptr)? t->left : t->right;
        delete oldNode;
    }
    balanceo(t);
}
int ancestro(NodeAVL *&t,int a,int b)
{
    if(t==nullptr)
        return -1;
    else if(t->dato < a && t->dato > b )
        return t->dato;
    else if(t->dato > a&& t->dato < b)
        return t->dato;
    else if(t->dato > a && t->dato > b)
        ancestro(t->left,a,b);
    else if(t->dato < a && t->dato < b)
        ancestro(t->right,a,b);
}
bool esHoja(NodeAVL *&t,int a)
{
    if(t==nullptr)
        return false;
    else if(t->dato >  a)
        esHoja(t->left,a);
    else if(t->dato < a)
        esHoja(t->right,a);
    else if(t->dato == a && t->left==nullptr && t->right==nullptr)
        return true;
    else
    {
        ;
    }
    
}

void verArbol(NodeAVL *&arbol, int n)
{
     if(arbol==NULL)
          return ;
     verArbol(arbol->right, n+1);

     for(int i=0; i<n; i++)
         cout<<"   ";

     cout<< arbol->dato <<endl;

     verArbol(arbol->left, n+1);
}
int main()
{
    NodeAVL *head=nullptr;
    insertar(7,head);
    insertar(8,head);
    insertar(9,head);
    insertar(10,head);
    insertar(11,head);
    insertar(12,head);    
    verArbol(head,0);
    cout<<endl;
    cout<< " ancestro :" << ancestro(head,13,8);
    return 0;
}