
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;
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

int EsHoja(NodeAVL *&r)
{
   return !r->right && !r->left;
}

void auxAltura(NodeAVL *&nod, int a, int *altura)
{
   /* Recorrido postorden */
   if(nod->left) auxAltura(nod->left, a+1, altura);
   if(nod->right) auxAltura(nod->right, a+1, altura);
   /* Proceso, si es un NodeAVL hoja, y su altura es mayor que la actual del
      árbol, actualizamos la altura actual del árbol */
   if(EsHoja(nod) && a > *altura) *altura = a;
}
int Vacio(NodeAVL *&r)
{
   return r==NULL;
}
int AlturaArbol(NodeAVL *&a, int *altura)
{
   *altura = 0;

   auxAltura(a, 0, altura); /* Función auxiliar */
   return *altura;
}
int Altura(NodeAVL *& a, int dat)
{
   int altura = 0;
   NodeAVL *actual = a;

   /* Todavía puede aparecer, ya que quedan NodeAVLs por mirar */
   while(!Vacio(actual)) {
      if(dat == actual->dato) return altura; /* encontrado: devolver altura */
      else {
         altura++; /* Incrementamos la altura, seguimos buscando */
         if(dat < actual->dato) actual = actual->left;
         else if(dat > actual->dato) actual = actual->right;
      }
   }
   return -1; /* No está en árbol, devolver -1 */
}
//Functions
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
        {
            doubleWithRightChild(t);
        }
        
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



NodeAVL * findMin(NodeAVL *t)
{
    if( t == nullptr )
        return nullptr;
    if( t->left == nullptr )
        return t;
    return findMin( t->left );
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

void verArbol(NodeAVL *&arbol, int n)
{
     if(arbol==NULL)
          return;
     verArbol(arbol->right, n+1);

     for(int i=0; i<n; i++)
         cout<<"   ";

     cout<< arbol->dato <<endl;

     verArbol(arbol->left, n+1);
}
void print(ofstream &t, NodeAVL *&arbol)
{
    if(arbol!=NULL)
    {
        if(arbol->left)
        {
            t<<arbol->dato<<" -> "<<arbol->left->dato<<endl;
        }
        if(arbol->right)
        {
            t<<arbol->dato<<" -> "<< arbol->right->dato<<endl;
        }
        print(t,arbol->left);
        cout<<arbol->dato<<endl;
        print(t,arbol->right);
    }
}
int main()
{
    NodeAVL *head=NULL;
    insertar(8,head);
    insertar(9,head);
    insertar(10,head);
    verArbol(head,0);
    return 0;
}